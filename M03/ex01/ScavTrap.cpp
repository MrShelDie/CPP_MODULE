#include <iostream>

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ScavTrap(name) {
	std::cout << "ScavTrap: " << name << " constructed\n";
}

ScavTrap::ScavTrap(const std::string& name) {
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap: " << name << " constructed with name\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	*this = other;
	std::cout << "ScavTrap: " << name << " copy constructed\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: " << name << " destructed\n";
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap: " << name << " is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target) {
	if (hitPoints == 0 || energyPoints == 0)
		return;
	std::cout << "ScavTrap " << name << " attacks "
			  << target << ", causing " << attackDamage
			  << " points of damage!\n";
	--energyPoints;
}