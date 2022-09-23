#ifndef _ROBOTOMY_REQUEST_FORM_H
#define _ROBOTOMY_REQUEST_FORM_H

#include "AForm.hpp"

class RobotomyRequestAForm: public AForm {

	public:

		RobotomyRequestAForm();
		RobotomyRequestAForm(const std::string& name);
		RobotomyRequestAForm(const RobotomyRequestAForm& other);
		~RobotomyRequestAForm();

		RobotomyRequestAForm& operator=(const RobotomyRequestAForm& other);

		virtual void execute(const Bureaucrat& executor) const;

};

#endif
