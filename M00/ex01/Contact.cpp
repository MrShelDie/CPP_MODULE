#include "Contact.hpp"

Contact::Contact() {
	firstName = "None";
	lastName = "None";
	nickname = "None";
	phoneNumber = "None";
	darkestSecret = "None";
}

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::Contact(const Contact &other) {
	copyFieldsFrom(other);
}

Contact::~Contact() {

}

Contact& Contact::operator=(const Contact &other) {
	copyFieldsFrom(other);
	return *this;
}

void Contact::copyFieldsFrom(const Contact &other) {
	firstName = other.firstName;
	lastName = other.lastName;
	nickname = other.nickname;
	phoneNumber = other.phoneNumber;
	darkestSecret = other.darkestSecret;
}