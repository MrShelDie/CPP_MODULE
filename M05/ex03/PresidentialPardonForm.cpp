#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	Form(25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(
		const std::string& name,
		const std::string& target) :
	Form(name, target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(
		const PresidentialPardonForm& other) :
	Form(other)
{

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm& PresidentialPardonForm::operator=(
		const PresidentialPardonForm& other)
{
	Form::operator=(other);
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	checkToExecute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";	
}
