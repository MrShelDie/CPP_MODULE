#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Form form("form1", Bureaucrat::MIN_GRADE + 1, 5);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}	

	try {
		Form form("form1", Bureaucrat::MAX_GRADE - 1, 5);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}	

	try {
		Form form("form1", 5, Bureaucrat::MIN_GRADE + 1);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}	

	try {
		Form form("form1", 5, Bureaucrat::MAX_GRADE - 1);
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	try {
		Bureaucrat bureaucrat("Bob", 42);
		std::cout << bureaucrat << "\n";
		Form form40("form 50", 50, 60);
		Form form50("form 40", 40, 60);
		std::cout << form50 << "\n";
		std::cout << form40 << "\n";
		bureaucrat.signForm(form40);
		bureaucrat.signForm(form50);
		std::cout << form50 << "\n";
		std::cout << form40 << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}

	return 0;
}
