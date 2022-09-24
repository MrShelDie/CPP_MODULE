#include "AForm.hpp"

AForm::AForm() :
	target("NoTarget"),
	name("NoName"),
	gradeToSign(Bureaucrat::MAX_GRADE),
	gradeToExecute(Bureaucrat::MAX_GRADE),
	formSigned(false)
{

}

AForm::AForm(
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

AForm::AForm(const int gradeToSign, const int gradeToExecute) :
	target("NoTarget"),
	name("NoName"),
	gradeToSign(gradeToSign),
	gradeToExecute(gradeToExecute), 
	formSigned(false)
{
	checkGrades();
}

AForm::AForm(const AForm& other) :
	target(other.target),
	name(other.name),
	gradeToSign(other.gradeToSign),
	gradeToExecute(other.gradeToExecute)
{

}

AForm::~AForm() {

}

AForm& AForm::operator=(const AForm& other) {
	if (&other != this) {
		const_cast<std::string&>(name) = other.name;
		const_cast<std::string&>(target) = other.target;
		const_cast<int&>(gradeToSign) = other.gradeToSign;
		const_cast<int&>(gradeToExecute) = other.gradeToExecute;
		formSigned = other.formSigned;
	}
	return *this;
}

const std::string& AForm::getName() const {
	return name;
}

const std::string& AForm::getTarget() const {
	return target;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

bool AForm::isSigned() const {
	return formSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() >= gradeToSign)
		throw GradeTooLowException();
	formSigned = true;	
}

void AForm::checkToExecute(const Bureaucrat& executor) const {
	if (!formSigned)
		throw FormNotSignedException();
	if (executor.getGrade() >= gradeToExecute)
		throw GradeTooLowException();
}

void AForm::checkGrades() const {
	if (gradeToSign < Bureaucrat::MAX_GRADE
			|| gradeToExecute < Bureaucrat::MAX_GRADE)
		throw GradeTooHighException(); 
	if (gradeToSign > Bureaucrat::MIN_GRADE
			|| gradeToExecute > Bureaucrat::MIN_GRADE)
		throw GradeTooLowException(); 
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "form isn't signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << obj.getName() << ", target: " << obj.getTarget()
	   << ", form signed " << obj.isSigned(); 
	return os;
}
