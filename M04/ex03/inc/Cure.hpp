#ifndef _CURE_H_
#define _CURE_H_

#include "AMateria.hpp"

class Cure : AMateria {

public:

	Cure();
	Cure(const Cure& other);
	~Cure();

	Cure& operator=(const Cure& other);

	AMateria* clone() const;

};

#endif