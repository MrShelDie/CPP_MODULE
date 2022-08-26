#include <iostream>
#include <iomanip>

#include "Executor.hpp"

Executor::Executor() : running(true) {

}

std::string Executor::promptInput(const std::string &msg) const {
	std::string userInput;

	std::cout << msg;
	std::cin >> userInput;
	while (isSpaceInput(userInput)) {
		std::cout << msg;
		std::cin >> userInput;
		std::cin.clear();
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return userInput;
}

bool Executor::isSpaceInput(const std::string &str) const {
	return str.find_first_not_of(" \f\n\r\t\v", 0) == std::string::npos;
}

void Executor::executeCommand(const std::string &command) {
	if (command == "ADD") {
		performAdd();
	} else if (command == "SEARCH") {
		performSearch();
	} else if (command == "EXIT") {
		performExit();
	} else {
		handleUnknownCommand();
	}
}

void Executor::performAdd() {
	if (phoneBook.getContactCount() == PhoneBook::MAX_CONTACT_COUNT) {
		printMaxContactAlert();
	} else {
		Contact contact = promptEnterContact();
		phoneBook.addContact(contact);
	}
}

void Executor::printMaxContactAlert() const {
	std::cout << "The phone book already contains the maximum number of contacts\n";
}

Contact Executor::promptEnterContact() const {
	std::string firstName = promptInput("Enter first name: ");
	std::string lastName = promptInput("Enter last name: ");
	std::string nickname = promptInput("Enter nickname: ");
	std::string phoneNumber = promptInput("Enter phone number: ");
	std::string darkestSecret = promptInput("Enter darkest secret: ");
	return Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

void Executor::performSearch() {
	displayAllContacts();
	size_t index = promptEnterIndex();
	tryDisplayContactByIndex(index);
}

void Executor::displayAllContacts() const {
	const size_t contactCount = phoneBook.getContactCount();
	for (size_t i = 0; i < contactCount; ++i) {
		tryDisplayContactByIndex(i);
	}
}

void Executor::tryDisplayContactByIndex(size_t index) const {
	try {
		displayContact(phoneBook.findContactByIndex(index), index);
	} catch(const std::out_of_range &e) {
		std::cerr << e.what() << '\n';
	}
}

void Executor::displayContact(const Contact &contact, size_t index) const {
	std::cout << std::setw(FIELD_WIDTH) << index << "|"
			  << std::setw(FIELD_WIDTH) << contact.getFirstName() << "|"
			  << std::setw(FIELD_WIDTH) << contact.getLastName() << "|"
			  << std::setw(FIELD_WIDTH) << contact.getNickname() << "\n";
}

size_t Executor::promptEnterIndex() const {
	std::cout << "Enter index: ";
	size_t index;
	while (!(std::cin >> index)) {
		std::cin.clear();
    	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Incorrect index input\n";
		std::cout << "Enter index: ";
	}
	return index;
}

void Executor::performExit() {
	running = false;
}

void Executor::handleUnknownCommand() const {
	std::cout << "Unknown command. Enter ADD/SEARCH/EXIT\n";
}

bool Executor::isRunning() const {
	return running;
}