#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("NoName"), grade(MIN_GRADE) {

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
}

Bureaucrat::~Bureaucrat() {

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (&other != this) {
		const_cast<std::string&>(name) = other.name;
		grade = other.grade;
	}
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::raiseGrade() {
	if (grade == MAX_GRADE)
		throw GradeTooHighException();
	--grade;
}

void Bureaucrat::lowerGrade() {
	if (grade == MIN_GRADE)
		throw GradeTooLowException();
	++grade;
}

void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << "\n";
	} catch (std::exception& e) {
		std::cout << name << " couldn’t sign " << form.getName()
				  << " because " <<  e.what() << "\n";
	}	
}	

void Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << "\n";	
	} catch (std::exception& e) {
		std::cout << name << " couldn’t execute " << form.getName()
				  << " because " << e.what() << "\n";
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Error: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Error: grade low high";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
