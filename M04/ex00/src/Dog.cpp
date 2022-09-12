#include <iostream>

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default contructor is called\n";
}

Dog::Dog(const Dog& other) : Animal("Dog") {
	std::cout << "Dog copy constructor is called\n";
}

Dog::~Dog() {
	std::cout << "Dog destructor is called\n";
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator is called\n";
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog: woof\n";
}
