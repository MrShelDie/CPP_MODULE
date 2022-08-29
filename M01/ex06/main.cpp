#include <iostream>

#include "Harl.hpp"

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "The number of parameters is not equal to 1\n";
		return 1;
	}

	Harl harl(argv[1]);
	harl.complain();

	return 0;
}