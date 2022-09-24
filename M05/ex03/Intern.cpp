#include <iostream>

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern& other) {

}

Intern::~Intern() {

}

Intern& Intern::operator=(const Intern& other) {
	return *this;
}

Form* Intern::makeForm(const std::string& name, const std::string& target) const {
	for (size_t i = 0; i < FORM_COUNT; ++i) {
		if (name == formPatterns[i].name) {
			Form* form = (this->*formPatterns[i].makeForm)(target);
			std::cout << "Intern creates " << form->getName() << "\n";
			return form;
		}
	}
	throw FormDoesNotExistException();
}

Form* Intern::makePresidentialPardonForm(const std::string& target) const {
	return new PresidentialPardonForm(PRES_PARDON, target);
}

Form* Intern::makeRobotomyRequestForm(const std::string& target) const {
	return new RobotomyRequestForm(ROB_REQ, target);
}

Form* Intern::makeShrubberyCreationForm(const std::string& target) const {
	return new ShrubberyCreationForm(SHRUB_CREAT, target);
}

const char* Intern::FormDoesNotExistException::what() const throw() {
	return "for with passed name doesn't exist";
}

const std::string Intern::PRES_PARDON = "presidential pardon";
const std::string Intern::ROB_REQ = "robotomy request";
const std::string Intern::SHRUB_CREAT = "shrubbery creation";

const Intern::FormPattern Intern::formPatterns[] = {
	{PRES_PARDON, &Intern::makePresidentialPardonForm},
	{ROB_REQ, &Intern::makeRobotomyRequestForm},
	{SHRUB_CREAT, &Intern::makeShrubberyCreationForm}
};
