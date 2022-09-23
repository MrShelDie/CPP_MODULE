#ifndef _PRESIDENTIAL_PARDON_FORM_H_
#define _PRESIDENTIAL_PARDON_FORM_H_

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name, const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		virtual void execute(const Bureaucrat& executor) const;

};

#endif
