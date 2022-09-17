#ifndef _BUREAUCRAT_H_
#define _BUREAUCRAT_H_

#include <string>
#include <ostream>

class Bureaucrat {

public:

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	Bureaucrat& operator=(const Bureaucrat& other);	

	const std::string& getName() const;
	int getGrade() const;

	void raiseGrade();
	void lowerGrade();

private:

	static const int MAX_GRADE = 1;
	static const int MIN_GRADE = 150;
	
	const std::string name;
	int grade;

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
