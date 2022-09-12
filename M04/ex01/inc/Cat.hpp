#ifndef _CAT_H_
#define _CAT_H_

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

public:

	Cat();
	Cat(const Cat& other);
	~Cat();

	Cat& operator=(const Cat& other);

	void makeSound() const;


private:

	Brain *brain;

};

#endif