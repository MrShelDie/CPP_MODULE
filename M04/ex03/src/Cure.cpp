#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure& other) : AMateria("cure") {
}

Cure::~Cure() {
}

Cure& Cure::operator=(const Cure& other) {
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}