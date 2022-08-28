#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(void) : name("default") {

}

Zombie::Zombie(const std::string& name) : name(name) {

}

Zombie::~Zombie() {
	std::cout << name << ": destroyed\n";
}

void Zombie::setName(const std::string& name) {
	this->name = name;
}

void Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}