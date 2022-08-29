#include <iostream>

#include "Harl.hpp"

Harl::Harl(const std::string& levelStr)
		: funcPtrs{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error},
		  levelStrings{"DEBUG", "INFO", "WARNING", "ERROR"} {

	int i = NB_LEVEL;
	level = i;
	while (--i >= 0) {
		if (levelStr == levelStrings[i]) {
			level = i;
		}	
	}
}

void Harl::complain(void) {
	switch (level) {
	case 0:
		debug();
	case 1:
		info();
	case 2:
		warning();
	case 3:
		error();
		break;
	default:
		other();
	}
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]\n"
				 "I love having extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
				 "I really do!\n\n";
}

void Harl::info(void) {
	std::cout << "[ INFO ]\n"
				 "I cannot believe adding extra bacon costs more money.\n"
				 "You didn't put enough bacon in my burger!\n"
				 "If you did, I wouldn't be asking for more!\n\n";
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]\n"
				 "I think I deserve to have some extra bacon for free.\n"
				 "I've been coming for years whereas you started working "
				 "here since last month.\n\n";
}

void Harl::error(void) {
	std::cout << "[ ERROR ]\n"
	 			 "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::other(void) {
	std::cout << "[ Probably complaining about insignificant problems ]\n";
}