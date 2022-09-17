#include "Form.hpp"

Form::Form() :
	name("NoName"),
	gradeToSign(Bureaucrat::MAX_GRADE),
	gradeToExecute(Bureaucrat::MAX_GRADE),
	formSigned(false)
{

}

Form::Form(
	const std::string& name,
	const int gradeToSign,
	const int gradeToExecute
) :
	name(name),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute), 
	formSigned(false)
{
	if (gradeToSign < Bureaucrat::MAX_GRADE
			|| gradeToExecute < Bureaucrat::MAX_GRADE)
		throw GradeTooHighException(); 
	if (gradeToSign > Bureaucrat::MIN_GRADE
			|| gradeToExecute > Bureaucrat::MIN_GRADE)
		throw GradeTooLowException(); 
}

Form::Form(const Form& other) :
	name("NoName"),
	gradeToSign(Bureaucrat::MAX_GRADE),
	gradeToExecute(Bureaucrat::MAX_GRADE)
{
	*this = other;
}

Form::~Form() {

}

Form& Form::operator=(const Form& other) {
	if (&other != this) {
		const_cast<std::string&>(name) = other.name;
		const_cast<int&>(gradeToSign) = other.gradeToSign;
		const_cast<int&>(gradeToExecute) = other.gradeToExecute;
		formSigned = other.formSigned;
	}
	return *this;
}

const std::string& Form::getName() const {
	return name;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

bool Form::isSigned() const {
	return formSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() >= gradeToSign)
		throw GradeTooLowException();
	formSigned = true;	
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade to high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade to low";
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName() << ", form signed " << obj.isSigned() << "\n";	
	return os;
}
