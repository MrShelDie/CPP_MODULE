#ifndef _MATERIA_SOURCE_H_
#define _MATERIA_SOURCE_H_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	MateriaSource();
	MateriaSource(const MateriaSource& other);
	~MateriaSource();

	MateriaSource& operator=(const MateriaSource& other);

	void learnMateria(AMateria*);
	AMateria* createMateria(const std::string& type);


private:

	static const size_t NB_INVENTORY_SLOTS = 4;

	AMateria* inventory[NB_INVENTORY_SLOTS];
	size_t nextEmptySlot;

};

#endif