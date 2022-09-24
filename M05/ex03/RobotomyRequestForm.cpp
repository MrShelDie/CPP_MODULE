#include <iostream>
#include <ctime>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	Form("NoName", "NoName", 72, 45)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(
		const std::string& name, const std::string& target) :
	Form(name, target, 72, 45)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(
		const RobotomyRequestForm& other) :
	Form(other)
{
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(
		const RobotomyRequestForm& other)
{
	Form::operator=(other);
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	checkToExecute(executor);
	std::cout << "* drilling noises... *\n";

	if (std::rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully\n";
	else
		std::cout << "robotomy failed\n";
}
