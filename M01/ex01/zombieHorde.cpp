#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N < 1) {
		throw std::bad_alloc();
	}

	Zombie* zombies = new Zombie[N];
	for (size_t i = 0; i < N; ++i) {
		zombies[i].setName(name);
	}
	return zombies;
}