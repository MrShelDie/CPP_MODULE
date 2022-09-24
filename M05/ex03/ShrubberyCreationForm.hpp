#ifndef _SHRUBBERY_CREATION_FORM_H_
#define _SHRUBBERY_CREATION_FORM_H_

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& name, const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		virtual void execute(const Bureaucrat& executor) const;
};

#endif
