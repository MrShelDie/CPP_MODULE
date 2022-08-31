#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

class Fixed {

public:

	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	Fixed& operator=(const Fixed& other);

	int getRawBits() const;
	void setRawBits(const int raw);


private:
	
	static const int NB_FRACTION_BITS = 8;

	int rawBits;

};

#endif