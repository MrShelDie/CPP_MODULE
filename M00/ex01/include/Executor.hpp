#ifndef EXECUTER_HPP
# define EXECUTER_HPP

# include <string>

# include "PhoneBook.hpp"

class Executor {
public:
	Executor();

	std::string promptEnterCommand();
	void executeCommand(const std::string &command);

	bool isRunning() const;

private:
	void performAdd();
	void performSearch();
	void performExit();
	void handleUnknownCommand();

	void printMaxContactAlert();

	Contact promptEnterContact();

	PhoneBook phoneBook;
	bool running;
};

#endif