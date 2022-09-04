#include <iostream>

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : DiamondTrap(name + "_clap_name") {
	std::cout << "DiamondTrap: " << name << " constructed\n";
}

DiamondTrap::DiamondTrap(const std::string& name) {
	this->name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "FragTrap: " << name << " constructed with name\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	ClapTrap::operator=(other);
	std::cout << "DiamondTrap: " << name << " assigned with operator\n";
	return *this;
}

void DiamondTrap::whoAmI() const {
	std::cout << "DiamondTrap: " << "my name is " << name
			  << ", my ClapTrap name is " << ClapTrap::name << "\n";
}