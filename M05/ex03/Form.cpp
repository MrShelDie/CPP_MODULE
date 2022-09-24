#include "Form.hpp"

Form::Form() :
	target("NoTarget"),
	name("NoName"),
	gradeToSign(Bureaucrat::MAX_GRADE),
	gradeToExecute(Bureaucrat::MAX_GRADE),
	formSigned(false)
{

}

Form::Form(
	const std::string& name,
	const std::string& target,
	const int gradeToSign,
	const int gradeToExecute
) :
	target(target),
	name(name),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute), 
	formSigned(false)
{
	checkGrades(); 
}

Form::Form(const int gradeToSign, const int gradeToExecute) :
	target("NoTarget"),
	name("NoName"),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute), 
	formSigned(false)
{
	checkGrades();
}

Form::Form(const Form& other) :
	target(other.target),
	name(other.name),
	gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute)
{

}

Form::~Form() {

}

Form& Form::operator=(const Form& other) {
	if (&other != this) {
		const_cast<std::string&>(name) = other.name;
		const_cast<std::string&>(target) = other.target;
		const_cast<int&>(gradeToSign) = other.gradeToSign;
		const_cast<int&>(gradeToExecute) = other.gradeToExecute;
		formSigned = other.formSigned;
	}
	return *this;
}

const std::string& Form::getName() const {
	return name;
}

const std::string& Form::getTarget() const {
	return target;
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

void Form::checkToExecute(const Bureaucrat& executor) const {
	if (!formSigned)
		throw FormNotSignedException();
	if (executor.getGrade() >= gradeToExecute)
		throw GradeTooLowException();
}

void Form::checkGrades() const {
	if (gradeToSign < Bureaucrat::MAX_GRADE
			|| gradeToExecute < Bureaucrat::MAX_GRADE)
		throw GradeTooHighException(); 
	if (gradeToSign > Bureaucrat::MIN_GRADE
			|| gradeToExecute > Bureaucrat::MIN_GRADE)
		throw GradeTooLowException(); 
}

const char* Form::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* Form::FormNotSignedException::what() const throw() {
	return "form isn't signed";
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName() << ", target: " << obj.getTarget()
	   << ", form signed " << obj.isSigned(); 
	return os;
}
