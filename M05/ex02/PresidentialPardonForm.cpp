#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("NoName", 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : Form(name, 25, 5) {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	Form::operator=(other);
	return *this;
}

