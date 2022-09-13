#ifndef _I_MATERIA_SOURCE_H_
#define _I_MATERIA_SOURCE_H_

#include "AMateria.hpp"

class IMateriaSource {

public:

	virtual ~IMateriaSource() {}

	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(const std::string& type) = 0;

};

#endif