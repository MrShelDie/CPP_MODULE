#ifndef _FORM_H_
#define _FORM_H_

#include <string>
#include <ostream>

#include "Bureaucrat.hpp"

class AForm {

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

	AForm();
	AForm(const std::string& name,
		  const std::string& target,
		  const int gradeToSign,
		  const int gradeToExecute);
	AForm(const AForm& other);
	virtual ~AForm();

	AForm& operator=(const AForm& other);

	virtual void execute(const Bureaucrat& executor) const = 0;

	void beSigned(const Bureaucrat& bureaucrat);

	const std::string& getName() const;
	const std::string& getTarget() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool isSigned() const;


protected:

	AForm(const int gradeToSign, const int gradeToExecute);

	void checkToExecute(const Bureaucrat& executor) const;

	const std::string target;


private:

	void checkGrades() const;

	const std::string name;
	const int gradeToSign;
	const int gradeToExecute;
	bool formSigned;

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
