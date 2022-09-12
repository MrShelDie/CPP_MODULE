#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice& other) : AMateria("ice") {
}

Ice::~Ice() {
}

Ice& Ice::operator=(const Ice& other) {
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}