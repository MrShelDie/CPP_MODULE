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
	contactCount = (contactCount + 1) % MAX_CONTACT_COUNT;
	contacts[contactCount] = contact; 
}

Contact PhoneBook::findContactByIndex(size_t index) const {
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
