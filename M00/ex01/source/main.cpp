#include <iostream>
#include <exception>

#include "Executor.hpp"

int main() {
	Executor executor;
	std::cin.exceptions(std::istream::eofbit);

	while (executor.isRunning()) {
		try {
			std::string command = executor.promptInput("(ADD/SEARCH/EXIT) > ");
			executor.executeCommand(command);	
		} catch(const std::ios_base::failure &e) {
			std::cout << "\n";
			break;
		}
	}
	
	return 0;
}