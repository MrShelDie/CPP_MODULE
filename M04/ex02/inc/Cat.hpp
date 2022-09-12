#ifndef _CAT_H_
#define _CAT_H_

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {

public:

	Cat();
	Cat(const Cat& other);
	~Cat();

	Cat& operator=(const Cat& other);

	void makeSound() const;
	Brain* getBrain() const;


private:

	Brain *brain;

};

#endif