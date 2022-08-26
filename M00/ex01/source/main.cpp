#include <iostream>

#include "Executor.hpp"

int main() {
	Executor executor;

	while (executor.isRunning()) {
		std::string command = executor.promptInput("(ADD/SEARCH/EXIT) > ");
		executor.executeCommand(command);
	}
	
	return 0;
}