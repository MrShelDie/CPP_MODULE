#ifndef _WRONG_CAT_H_
#define _WRONG_CAT_H_

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	WrongCat();
	WrongCat(const WrongCat& other);
	~WrongCat();

	WrongCat& operator=(const WrongCat& other);

	void makeSound() const;

};

#endif