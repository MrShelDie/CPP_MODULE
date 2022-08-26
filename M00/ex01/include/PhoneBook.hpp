#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook {
public:
	static const int MAX_CONTACT_COUNT = 8;

	PhoneBook();
	PhoneBook(const PhoneBook &other);

	PhoneBook& operator=(const PhoneBook &other);

	void addContact(const Contact &contact);
	Contact findContactByIndex(size_t index) const;
	
	size_t getContactCount() const;

private:
	void copyContacts(const Contact contacts[], size_t contactCount);

	Contact contacts[MAX_CONTACT_COUNT];
	size_t contactCount;
};

#endif