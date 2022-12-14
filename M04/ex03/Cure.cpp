#include <iostream>

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure& other) : AMateria("cure") {
	(void)other;
}

Cure::~Cure() {
}

Cure& Cure::operator=(const Cure& other) {
	(void)other;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}