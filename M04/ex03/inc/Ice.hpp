#ifndef _ICE_H_
#define _ICE_H_

#include "AMateria.hpp"

class Ice : AMateria {

public:

	Ice();
	Ice(const Ice& other);
	~Ice();

	Ice& operator=(const Ice& other);

	AMateria* clone() const;

};

#endif