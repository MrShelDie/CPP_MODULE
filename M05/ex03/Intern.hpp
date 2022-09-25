#ifndef _INTERN_H_
#define _INTERN_H_

#include <string>

#include "Form.hpp"


class Intern {

public:

	class FormDoesNotExistException : public std::exception {
	public:
		const char* what() const throw();
	};

	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);

	Form* makeForm(const std::string& name, const std::string& target) const;	


private:

	Form* makePresidentialPardonForm(const std::string& target) const;
	Form* makeRobotomyRequestForm(const std::string& target) const;
	Form* makeShrubberyCreationForm(const std::string& target) const;

	static const size_t FORM_COUNT = 3;
	static const std::string PRES_PARDON;
	static const std::string ROB_REQ;
	static const std::string SHRUB_CREAT;

	typedef Form* (Intern::*FormMaker)(const std::string& target) const;

	struct FormPattern {
		std::string name;
		FormMaker makeForm;
	};

	static const FormPattern formPatterns[];	
};

#endif
