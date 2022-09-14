#include "Character.hpp"

Character::Character() : name("NoName") {
	for (size_t i = 0; i < NB_INVENTORY_SLOTS; ++i)
		inventory[i] = NULL;
}

Character::Character(const std::string& name) : name(name) {
	for (size_t i = 0; i < NB_INVENTORY_SLOTS; ++i)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.name) {
	for (size_t i = 0; i < NB_INVENTORY_SLOTS; ++i) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character::~Character() {
	for (size_t i = 0; i < NB_INVENTORY_SLOTS; ++i)
		delete inventory[i];
}

Character& Character::operator=(const Character& other) {
	if (&other == this)
		return *this;
	name = other.name;
	for (size_t i = 0; i < NB_INVENTORY_SLOTS; ++i) {
		delete inventory[i];
		inventory[i] = NULL;
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
	}
	return *this;
}

const std::string& Character::getName() const {
	return name;
}

AMateria* Character::getMateria(int idx) const {
	if (static_cast<size_t>(idx) < NB_INVENTORY_SLOTS)
		return inventory[idx];
	return NULL;
}

void Character::equip(AMateria* m) {
	size_t i = 0;
	while (inventory[i] && i < NB_INVENTORY_SLOTS)
		++i;
	if (i != NB_INVENTORY_SLOTS)
		inventory[i] = m;
}

void Character::unequip(int idx) {
	if (static_cast<size_t>(idx) < NB_INVENTORY_SLOTS)
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (static_cast<size_t>(idx) < NB_INVENTORY_SLOTS && inventory[idx])
		inventory[idx]->use(target);
}
