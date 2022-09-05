#include <iostream>

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() {
	init();
	std::cout << "ScavTrap: " << name << " constructed\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	init();
	std::cout << "ScavTrap: " << name << " constructed with name\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap: " << name << " copy constructed\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: " << name << " destructed\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "ScavTrap: " << name << " assigned with operator\n";
	return *this;
}


void ScavTrap::init() {
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}


void ScavTrap::attack(const std::string& target) {
	if (hitPoints == 0 || energyPoints == 0)
		return;
	std::cout << "ScavTrap " << name << " attacks "
			  << target << ", causing " << attackDamage
			  << " points of damage!\n";
	--energyPoints;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap: " << name << " is now in Gate keeper mode\n";
}