#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <ostream>

class Fixed {

public:

	static Fixed& min(Fixed& lhs, Fixed& rhs);
	static const Fixed& min(const Fixed& lhs, const Fixed& rhs);

	static Fixed& max(Fixed& lhs, Fixed& rhs);
	static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int number);
	Fixed(const float number);
	~Fixed();

	Fixed& operator=(const Fixed& other);

	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits() const;
	void setRawBits(const int raw);

	float toFloat() const;
	int toInt() const;


private:
	
	static const int NB_FRACTION_BITS = 8;
	static const int CONVERT_COEFFICIENT = 1 << NB_FRACTION_BITS;

	int rawBits;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif