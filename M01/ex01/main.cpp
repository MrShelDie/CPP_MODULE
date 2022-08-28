#include <iostream>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void) {
	const int NB_ZOMBIES = 5;
	
	Zombie* zombies;

	try {
		zombies = zombieHorde(NB_ZOMBIES, "Stive");
	} catch (const std::bad_alloc& e) {
		std::cerr << e.what() << '\n';
		return 0;
	}
	
	for (size_t i = 0; i < NB_ZOMBIES; ++i) {
		zombies[i].announce();
	}

	delete[] zombies;

	return 0;
}