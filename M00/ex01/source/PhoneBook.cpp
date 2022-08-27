#include <stdexcept>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), nextContactIndex(0) {

}

PhoneBook::PhoneBook(const PhoneBook &other) {
	copyPhoneBook(other);
}

PhoneBook& PhoneBook::operator=(const PhoneBook &other) {
	copyPhoneBook(other);
	return *this;
}

void PhoneBook::copyPhoneBook(const PhoneBook &other) {
	contactCount = other.contactCount;
	nextContactIndex = other.nextContactIndex;
	copyContacts(other.contacts, contactCount);
}

void PhoneBook::addContact(const Contact &contact) {
	contacts[nextContactIndex] = contact;
	nextContactIndex = (nextContactIndex + 1) % MAX_CONTACT_COUNT;
	if (contactCount < MAX_CONTACT_COUNT) {
		++contactCount;
	}
}

Contact PhoneBook::findContactByIndex(size_t index) const {
	if (index >= contactCount) {
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
