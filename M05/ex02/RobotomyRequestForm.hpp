#ifndef _ROBOTOMY_REQUEST_FORM_H
#define _ROBOTOMY_REQUEST_FORM_H

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& name, const std::string& targer);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		virtual void execute(const Bureaucrat& executor) const;
};

#endif
