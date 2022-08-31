#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	rawBits = other.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return rawBits;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called\n";
	rawBits = raw;
}