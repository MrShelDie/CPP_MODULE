#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name) {

}

Zombie::~Zombie() {
	std::cout << name << ": destroyed\n";
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}