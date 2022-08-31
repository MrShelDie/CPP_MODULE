#include <iostream>
#include <cmath>

#include "Fixed.hpp"


Fixed::Fixed() : rawBits(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed::Fixed(const int number) : rawBits(number << NB_FRACTION_BITS) {
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float number) : rawBits(roundf(number * CONVERT_COEFFICIENT)) {
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}



Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	rawBits = other.rawBits;
	return *this;
}



Fixed Fixed::operator+(const Fixed& other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) {
	return Fixed(this->toFloat() / other.toFloat());
}



Fixed& Fixed::operator++() {
	++rawBits;
	return *this;
}

Fixed& Fixed::operator--() {
	--rawBits;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed other = *this;
	++rawBits;
	return other;
}

Fixed Fixed::operator--(int) {
	Fixed other = *this;
	--rawBits;
	return other;
}



bool Fixed::operator>(const Fixed& other) {
	return rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed& other) {
	return rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed& other) {
	return rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed& other) {
	return rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed& other) {
	return rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed& other) {
	return rawBits != other.rawBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return os << fixed.toFloat();
}



int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return rawBits;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called\n";
	rawBits = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(rawBits) / CONVERT_COEFFICIENT;
}

int Fixed::toInt() const {
	return rawBits >> NB_FRACTION_BITS;
}