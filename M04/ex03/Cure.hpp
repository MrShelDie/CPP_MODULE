#ifndef _CURE_H_
#define _CURE_H_

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {

public:

	Cure();
	Cure(const Cure& other);
	~Cure();

	Cure& operator=(const Cure& other);

	AMateria* clone() const;
	void use(ICharacter& target);

};

#endif