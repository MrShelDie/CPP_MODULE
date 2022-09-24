#ifndef _SHRUBBERY_CREATION_FORM_H_
#define _SHRUBBERY_CREATION_FORM_H_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
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
