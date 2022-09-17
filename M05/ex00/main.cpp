#include <iostream>

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("Bob", 0);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	try {
		Bureaucrat bureaucrat("Bob", 151);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}	

	try {
		Bureaucrat bureaucrat("Bob", 1);
		bureaucrat.raiseGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	try {
		Bureaucrat bureaucrat("Bob", 150);
		bureaucrat.lowerGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	try {
		Bureaucrat bureaucrat("Bob", 42);
		std::cout << bureaucrat << "\n";
		bureaucrat.lowerGrade();
		std::cout << bureaucrat << "\n";
		bureaucrat.raiseGrade();
		std::cout << bureaucrat << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	return 0;
}
