#include <iostream>
#include <cmath>

#include "Fixed.hpp"


Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
	return lhs < rhs ? lhs : rhs;
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	return lhs < rhs ? lhs : rhs;
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
	return lhs > rhs ? lhs : rhs;
}

const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	return lhs > rhs ? lhs : rhs;
}



Fixed::Fixed() : rawBits(0) {
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::Fixed(const int number) : rawBits(number << NB_FRACTION_BITS) {
}

Fixed::Fixed(const float number) : rawBits(roundf(number * CONVERT_COEFFICIENT)) {
}

Fixed::~Fixed() {
}



Fixed& Fixed::operator=(const Fixed& other) {
	rawBits = other.rawBits;
	return *this;
}



Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
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



bool Fixed::operator>(const Fixed& other) const {
	return rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
	return rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
	return rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
	return rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
	return rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
	return rawBits != other.rawBits;
}



std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	return os << fixed.toFloat();
}



int Fixed::getRawBits() const {
	return rawBits;
}

void Fixed::setRawBits(const int raw) {
	rawBits = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(rawBits) / CONVERT_COEFFICIENT;
}

int Fixed::toInt() const {
	return rawBits >> NB_FRACTION_BITS;
}