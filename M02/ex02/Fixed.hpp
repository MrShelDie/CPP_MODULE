#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed {

public:

	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int number);
	Fixed(const float number);
	~Fixed();

	Fixed& operator=(const Fixed& other);

	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	bool operator>(const Fixed& other);
	bool operator<(const Fixed& other);
	bool operator>=(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator==(const Fixed& other);
	bool operator!=(const Fixed& other);

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