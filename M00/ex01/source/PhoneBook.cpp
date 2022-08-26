#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	contactCount = 0;
}

PhoneBook::PhoneBook(const PhoneBook &other) {
	contactCount = other.contactCount;
	copyContacts(other.contacts, contactCount);
}

PhoneBook& PhoneBook::operator=(const PhoneBook &other) {
	contactCount = other.contactCount;
	copyContacts(other.contacts, contactCount);
	return *this;
}

void PhoneBook::addContact(const Contact &contact) {
	if (contactCount == MAX_CONTACT_COUNT) {
		throw BufferOverflowException("The phone book already has the maximum number of contacts");
	}
	contacts[++contactCount] = contact; 
}

Contact PhoneBook::findContactByIndex(size_t index) {
	if (index > contactCount) {
		throw std::out_of_range("Invalid contact index");
	}
	return contacts[index];
}

void PhoneBook::copyContacts(const Contact contacts[], size_t contactCount) {
	for (size_t i = 0; i < contactCount; ++i) {
		this->contacts[i] = contacts[i];
	}
}

size_t PhoneBook::getContactCount() const {
	return contactCount;
}
