#ifndef _ROBOTOMY_REQUEST_FORM_H
#define _ROBOTOMY_REQUEST_FORM_H

#include "Form.hpp"

class RobotomyRequestForm: public Form {

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& name);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

};

#endif
