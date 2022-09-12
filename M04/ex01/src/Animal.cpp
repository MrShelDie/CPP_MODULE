#include <iostream>

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal default contructor is called\n";
}

Animal::Animal(const std::string& type) : type(type) {
	std::cout << "Animal contructor with parameter is called\n";
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor is called\n";
	*this = other;
}

Animal::~Animal() {
	std::cout << "Animal destructor is called\n";
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal assignment operator is called\n";
	if (&other != this)
		type = other.type;
	return *this;
}

void Animal::makeSound() const {
}

std::string Animal::getType() const {
	return type;
}
