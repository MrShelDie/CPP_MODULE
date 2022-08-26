#include <iostream>

#include "Executor.hpp"

Executor::Executor() : running(true) {

}

std::string Executor::promptEnterCommand() {
	std::cout << "(ADD/SEARCH/EXIT) > ";
	std::string userInput;
	std::cin >> userInput;
	return userInput;
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

void Executor::printMaxContactAlert() {
	std::cout << "The phone book already contains the maximum number of contacts"
			  << std::endl;
}

Contact Executor::promptEnterContact() {

}

void Executor::performSearch() {

}

void Executor::performExit() {
	running = false;
}

void Executor::handleUnknownCommand() {
	std::cout << "Unknown command. Enter ADD/SEARCH/EXIT" << std::endl;
}

bool Executor::isRunning() const {
	return running;
}