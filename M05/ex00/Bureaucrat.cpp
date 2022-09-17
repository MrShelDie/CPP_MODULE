#include "Bureaucrat.hpp"

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
