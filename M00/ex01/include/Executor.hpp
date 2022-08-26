#ifndef EXECUTER_HPP
# define EXECUTER_HPP

# include <string>

# include "PhoneBook.hpp"

class Executor {
public:
	Executor();

	std::string promptInput(const std::string &msg) const;
	void executeCommand(const std::string &command);

	bool isRunning() const;

private:
	void performAdd();
	void performSearch();
	void performExit();
	void handleUnknownCommand() const;

	void displayAllContacts() const;
	void tryDisplayContactByIndex(size_t index) const;
	void displayContact(const Contact &contact, size_t index) const;

	Contact promptEnterContact() const;
	size_t promptEnterIndex() const;
	
	void printMaxContactAlert() const;

	bool isSpaceInput(const std::string &str) const;

	static const size_t FIELD_WIDTH = 10;

	PhoneBook phoneBook;
	bool running;
};

#endif