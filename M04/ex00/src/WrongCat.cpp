#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default contructor is called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor is called\n";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor is called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assignment operator is called\n";
	if (&other != this)
		type = other.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat: meow\n";
}
