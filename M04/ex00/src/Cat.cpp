#include <iostream>

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default contructor is called\n";
}

Cat::Cat(const Cat& other) : Animal("Cat") {
	(void)other;
	std::cout << "Cat copy constructor is called\n";
}

Cat::~Cat() {
	std::cout << "Cat destructor is called\n";
}

Cat& Cat::operator=(const Cat& other) {
	(void)other;
	std::cout << "Cat assignment operator is called\n";
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat: meow\n";
}
