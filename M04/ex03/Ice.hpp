#ifndef _ICE_H_
#define _ICE_H_

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

public:

	Ice();
	Ice(const Ice& other);
	~Ice();

	Ice& operator=(const Ice& other);

	AMateria* clone() const;
	void use(ICharacter& target);

};

#endif