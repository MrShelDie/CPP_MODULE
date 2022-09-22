#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("NoName", 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : Form(name, 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	Form::operator=(other);
	return *this;
}

