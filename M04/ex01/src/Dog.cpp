#include <iostream>

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default contructor is called\n";
	brain = new Brain;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor is called\n";
	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog destructor is called\n";
	delete brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator is called\n";
	if (&other != this) {
		type = other.type;
		*brain = *other.brain;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog: woof\n";
}
