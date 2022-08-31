#include <iostream>

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

void test(int N, std::string name) {
	Zombie* zombies;

	zombies = zombieHorde(N, name);
	
	for (size_t i = 0; i < N; ++i) {
		zombies[i].announce();
	}

	delete[] zombies;
}

int main(void) {
	
	try {
		test(5, "Stive");
		test(0, "Bob");
		test(-1, "Bill");
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}

	return 0;
}