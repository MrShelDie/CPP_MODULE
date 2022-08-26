#include <iostream>

#include "Executor.hpp"

int main() {
	Executor executor;

	while (executor.isRunning()) {
		std::string command = executor.promptEnterCommand();
		executor.executeCommand(command);
	}
	
	return 0;
}