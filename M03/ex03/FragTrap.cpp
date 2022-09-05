#include <iostream>

#include "FragTrap.hpp"


FragTrap::FragTrap() {
	init();
	std::cout << "FragTrap: " << name << " constructed\n";
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	init();
	std::cout << "FragTrap: " << name << " constructed with name\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap: " << name << " copy constructed\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: " << name << " destructed\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "FragTrap: " << name << " assigned with operator\n";
	return *this;
}


void FragTrap::init() {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}


void FragTrap::attack(const std::string& target) {
	if (hitPoints == 0 || energyPoints == 0)
		return;
	std::cout << "FragTrap " << name << " attacks "
			  << target << ", causing " << attackDamage
			  << " points of damage!\n";
	--energyPoints;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap: " << name << " Give me five!\n";
}
