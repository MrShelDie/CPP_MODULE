#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

#include "Executor.hpp"

Executor::Executor() : running(true) {

}

std::string Executor::promptInput(const std::string &msg) const {
	std::cout << msg;

	std::string userInput;
	std::cin >> userInput;

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
	Contact contact = promptEnterContact();
	phoneBook.addContact(contact);
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
	displayAllContactsShortInfo();
	size_t index = promptEnterIndex();
	tryDisplayContactFullInfoByIndex(index);
}

void Executor::displayAllContactsShortInfo() const {
	const size_t contactCount = phoneBook.getContactCount();
	for (size_t i = 0; i < contactCount; ++i) {
		tryDisplayContactShortInfoByIndex(i);
	}
}

void Executor::tryDisplayContactShortInfoByIndex(size_t index) const {
	try {
		displayContactShortInfo(phoneBook.findContactByIndex(index), index);
	} catch(const std::out_of_range &e) {
		std::cerr << e.what() << '\n';
	}
}

void Executor::displayContactShortInfo(const Contact &contact, size_t index) const {
	std::string truncatedIndex = truncStr(sizeToString(index));
	std::string truncatedFirstName = truncStr(contact.getFirstName());
	std::string truncatedLastName = truncStr(contact.getLastName());
	std::string truncatedNickname = truncStr(contact.getNickname());

	std::cout << std::setw(FIELD_WIDTH) << truncatedIndex << "|"
			  << std::setw(FIELD_WIDTH) << truncatedFirstName << "|"
			  << std::setw(FIELD_WIDTH) << truncatedLastName << "|"
			  << std::setw(FIELD_WIDTH) << truncatedNickname << "\n";
}

void Executor::tryDisplayContactFullInfoByIndex(size_t index) const {
	try {
		displayContactFullInfo(phoneBook.findContactByIndex(index), index);
	} catch(const std::out_of_range &e) {
		std::cerr << e.what() << '\n';
	}
}

void Executor::displayContactFullInfo(const Contact &contact, size_t index) const {
	std::cout << "Index: " << index << "\n"
			  << "First name: " << contact.getFirstName() << "\n"
			  << "Last name: " << contact.getLastName() << "\n"
			  << "Nickname: " << contact.getNickname() << "\n"
			  << "Phone number: " << contact.getPhoneNumber() << "\n"
			  << "Darkest secret: " << contact.getDarkestSecret() << "\n";
}

std::string Executor::truncStr(std::string str) const {
	if (str.size() >= FIELD_WIDTH) {
		str.resize(FIELD_WIDTH);
		str[FIELD_WIDTH - 1] = '.';
	}
	return str;
}

std::string Executor::sizeToString(size_t num) const {
	std::ostringstream oStringStream;
	oStringStream << num;
	return oStringStream.str();
}

size_t Executor::promptEnterIndex() const {
	const std::string msg = "Enter index: ";
	size_t index;

	std::cout << msg;
	while (!(std::cin >> index) || index >= phoneBook.getContactCount()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Incorrect input\n";
		std::cout << msg;
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