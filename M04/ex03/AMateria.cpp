#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria() : type("materia") {
}

AMateria::AMateria(const std::string& type) : type(type) {
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
}

AMateria::~AMateria() {
}

AMateria& AMateria::operator=(const AMateria& other) {
	type = other.type;
	return *this;
}

const std::string& AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	(void)target;
	std::cout << "* does nothing *\n";
}