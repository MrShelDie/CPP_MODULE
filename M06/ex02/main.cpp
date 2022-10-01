#include <ctime>
#include <cstdlib>
#include <iostream>
#include <typeinfo>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
	Base* result;
	switch (std::rand() % 3) {
		case 0:
			result = new A();
			break;
		case 1:
			result = new B();
			break;
		case 2:
			result = new C();
			break;
	}
	return result;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "Pointer to A\n"; 
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "Pointer to B\n"; 
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "Pointer to C\n"; 
	} else {
		std::cout << "Unknown pointer\n";	
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
	} catch (std::bad_cast& e) {
		try {
			(void)dynamic_cast<B&>(p);
		} catch (std::bad_cast& e) {
			try {
				(void)dynamic_cast<C&>(p);
			} catch (std::bad_cast& e) {	
				std::cout << "Unknown pointer\n";	
				return;
			}
			std::cout << "Pointer to C\n"; 
			return;	
		}
		std::cout << "Pointer to B\n"; 
		return;	
	}		
	std::cout << "Pointer to A\n"; 
}

int main() {
	const size_t SIZE = 5;
	Base* arr[SIZE];

	std::srand(std::time(NULL));

	for (size_t i = 0; i < SIZE; ++i) {
		arr[i] = generate();	
	}
	
	for (size_t i = 0; i < SIZE; ++i) {
		identify(arr[i]);
	}

	std::cout << "-----------------\n";

	for (size_t i = 0; i < SIZE; ++i) {
		identify(*arr[i]);
	}

	return 0;
}
