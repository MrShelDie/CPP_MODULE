#ifndef _FORM_H_
#define _FORM_H_

#include <string>
#include <ostream>

#include "Bureaucrat.hpp"

class Form {

public:

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	Form();
	Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
	Form(const Form& other);
	~Form();

	Form& operator=(const Form& other);

	const std::string& getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool isSigned() const;

	void beSigned(const Bureaucrat& bureaucrat);


private:

	const std::string name;
	const int gradeToSign;
	const int gradeToExecute;
	bool formSigned;

};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
