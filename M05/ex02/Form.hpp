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

	class FormNotSignedException : public std::exception {
	public:
		const char* what() const throw();
	};

	Form();
	Form(const std::string& name,
		  const std::string& target,
		  const int gradeToSign,
		  const int gradeToExecute);
	Form(const Form& other);
	virtual ~Form();

	Form& operator=(const Form& other);

	virtual void execute(const Bureaucrat& executor) const = 0;

	void beSigned(const Bureaucrat& bureaucrat);

	const std::string& getName() const;
	const std::string& getTarget() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool isSigned() const;


protected:

	Form(const int gradeToSign, const int gradeToExecute);

	void checkToExecute(const Bureaucrat& executor) const;

	const std::string target;


private:

	void checkGrades() const;

	const std::string name;
	const int gradeToSign;
	const int gradeToExecute;
	bool formSigned;

};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
