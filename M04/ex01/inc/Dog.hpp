#ifndef _DOG_H_
#define _DOG_H_

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

public:

	Dog();
	Dog(const Dog& other);
	~Dog();

	Dog& operator=(const Dog& other);
	
	void makeSound() const;


private:

	Brain *brain;

};

#endif