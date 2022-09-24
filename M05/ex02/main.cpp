#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		ShrubberyCreationForm shrubberyCreationForm("ShrubberyForm", "SomeShrubbery");
		Bureaucrat bob("bob", 146);
		Bureaucrat bill("bill", 135);
		Bureaucrat mike("mike", 100);

		bob.signForm(shrubberyCreationForm);
		mike.executeForm(shrubberyCreationForm);
		bill.signForm(shrubberyCreationForm);
		mike.executeForm(shrubberyCreationForm);
	}

	std::cout << "\n";

	{
		RobotomyRequestForm robotomyRequestForm("RobotomyForm", "SomeRobot");
		Bureaucrat bob("bob", 146);
		Bureaucrat bill("bill", 70);
		Bureaucrat mike("mike", 40);

		bob.signForm(robotomyRequestForm);
		mike.executeForm(robotomyRequestForm);
		bill.signForm(robotomyRequestForm);
		mike.executeForm(robotomyRequestForm);
		mike.executeForm(robotomyRequestForm);
		mike.executeForm(robotomyRequestForm);
		mike.executeForm(robotomyRequestForm);
		mike.executeForm(robotomyRequestForm);
	}

	std::cout << "\n";

	{
		PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm", "SomeTarget");
		Bureaucrat bob("bob", 30);
		Bureaucrat bill("bill", 15);
		Bureaucrat mike("mike", 3);

		bob.signForm(presidentialPardonForm);
		mike.executeForm(presidentialPardonForm);
		bill.signForm(presidentialPardonForm);
		mike.executeForm(presidentialPardonForm);
	}

	return 0;
}
