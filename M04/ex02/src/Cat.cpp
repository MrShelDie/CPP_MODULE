#include <iostream>

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "Cat default contructor is called\n";
	brain = new Brain;
}

Cat::Cat(const Cat& other) : AAnimal("Cat") {
	std::cout << "Cat copy constructor is called\n";
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat destructor is called\n";
	delete brain;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator is called\n";
	if (&other != this)
		*brain = *other.brain;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat: meow\n";
}

Brain* Cat::getBrain() const {
	return brain;
}
