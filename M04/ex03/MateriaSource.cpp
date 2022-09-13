#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : nextEmptySlot(0) {
	for (size_t i = 0; i < NB_INVENTORY_SLOTS; ++i)
		inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : nextEmptySlot(other.nextEmptySlot)
{
	size_t i = 0;
	for (; i < nextEmptySlot; ++i)
		inventory[i] = other.inventory[i]->clone();
	for (; i < NB_INVENTORY_SLOTS; ++i)
		inventory[i] = NULL;
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < nextEmptySlot; ++i)
		delete inventory[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (&other == this)
		return *this;
	for (size_t i = 0; i < nextEmptySlot; ++i) {
		delete inventory[i];
		inventory[i] = NULL;
	}
	nextEmptySlot = other.nextEmptySlot;
	for (size_t i = 0; i < nextEmptySlot; ++i)
		inventory[i] = other.inventory[i]->clone();
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	if (nextEmptySlot < NB_INVENTORY_SLOTS)
		inventory[nextEmptySlot++] = m;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (size_t i = 0; i < nextEmptySlot; ++i) {
		if (inventory[i]->getType() == type)
			return inventory[i]->clone();
	}
	return NULL;
}
