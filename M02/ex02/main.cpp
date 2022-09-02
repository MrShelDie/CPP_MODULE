#include <iostream>

#include "Fixed.hpp"

int main( void ) {
	
	Fixed 		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "---------------------------------\n";

	const Fixed A(42.21f);
	std::cout << A.toFloat() << "\n";

	Fixed C;
	C = A;
	std::cout << C.toFloat() << "\n";

	const Fixed B(5.05f);
	std::cout << B.toFloat() << "\n";

	std::cout << "(Fixed::max(A, B) == A): " << (Fixed::max(A, B) == A) << "\n";
	std::cout << "(Fixed::min(A, B) == B): " << (Fixed::min(A, B) == B) << "\n";
	std::cout << "(Fixed::min(a, b) == a): " << (Fixed::min(a, b) == a) << "\n";

	std::cout << "(A > B): " << (A > B) << "\n";
	std::cout << "(A >= B): " << (A >= B) << "\n";
	std::cout << "!(A == B): " << !(A == B) << "\n";
	std::cout << "(A != B): " << (A != B) << "\n";
	std::cout << "!(A <= B): " << !(A <= B) << "\n";
	std::cout << "!(A < B): " << !(A < B) << "\n";

	std::cout << "((A + B) == 42.21f + 5.05f): " << ((A + B) == 42.21f + 5.05f) << "\n";
	std::cout << "((A - B) == 42.21f - 5.05f): " << ((A - B) == 42.21f - 5.05f) << "\n";
	std::cout << "A * B: " << A * B << "\n";
	std::cout << "A / B: " << A / B << "\n";

	return 0;
}