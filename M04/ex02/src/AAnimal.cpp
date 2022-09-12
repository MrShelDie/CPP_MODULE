#include <iostream>

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
	std::cout << "AAnimal default contructor is called\n";
}

AAnimal::AAnimal(const std::string& type) : type(type) {
	std::cout << "AAnimal contructor with parameter is called\n";
}

AAnimal::AAnimal(const AAnimal& other) {
	std::cout << "AAnimal copy constructor is called\n";
	*this = other;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor is called\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "AAnimal assignment operator is called\n";
	if (&other != this)
		type = other.type;
	return *this;
}

void AAnimal::makeSound() const {
}

std::string AAnimal::getType() const {
	return type;
}
