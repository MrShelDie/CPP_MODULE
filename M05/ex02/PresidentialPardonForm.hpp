#ifndef _PRESIDENTIAL_PARDON_FORM_H_
#define _PRESIDENTIAL_PARDON_FORM_H_

#include "Form.hpp"

class PresidentialPardonForm: public Form {

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

};

#endif
