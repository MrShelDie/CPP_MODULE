#include <iostream>

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : name("default_clap_name") {
	init();
	std::cout << "DiamondTrap: " << name << " constructed\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name), FragTrap(name), ScavTrap(name), name(name + "_clap_name")
{
	init();
	std::cout << "DiamondTrap: " << this->name << " constructed with name\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	name = other.name;
	std::cout << "DiamondTrap: " << name << " copy constructed\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	ClapTrap::operator=(other);
	name = other.name;
	std::cout << "DiamondTrap: " << name << " assigned with operator\n";
	return *this;
}


void DiamondTrap::init() {
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}


DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap: " << name << " destructed\n";
}

void DiamondTrap::whoAmI() const {
	std::cout << "DiamondTrap: " << "my name is " << name
			  << ", my ClapTrap name is " << ClapTrap::name << "\n";
}
