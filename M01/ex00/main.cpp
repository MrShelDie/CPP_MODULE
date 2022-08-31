#include <iostream>

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
	Zombie* bob;

	try {
		bob = newZombie("Bob");	
	} catch (const std::bad_alloc& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}
	
	bob->announce();
	delete bob;

	randomChump("Bill");

	return 0;
}