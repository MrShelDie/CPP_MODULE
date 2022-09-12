#include <iostream>

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default contructor is called\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor is called\n";
}

Cat::~Cat() {
	std::cout << "Cat destructor is called\n";
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator is called\n";
	if (&other != this)
		type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat: meow\n";
}
