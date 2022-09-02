#include <iostream>
#include <climits>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
		: name("default"), hitPoints(10),
		  energyPoints(10), attackDamage(0) {
	std::cout << "Claptrap: " << name << " constructed\n";
}

ClapTrap::ClapTrap(std::string name)
		: name(name), hitPoints(10),
		  energyPoints(10), attackDamage(0) {
	std::cout << "Claptrap: " << name << " constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "Claptrap: " << name << " copy constructed\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "Claptrap: " << name << " destructed\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "Claptrap: " << name << " assigned with operator\n";
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints == 0 || energyPoints == 0)
		return;
	std::cout << "ClapTrap " << name << " attacks "
			  << target << ", causing " << attackDamage
			  << " points of damage!\n";
	--energyPoints;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "ClapTrap " << name << " took " << amount
			  << " points of damage\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints == 0 || energyPoints == 0)
		return;
	if (hitPoints + amount < hitPoints)
		hitPoints = UINT_MAX;
	else
		hitPoints += amount;
	std::cout << name << " got repaired by " << amount
			  << " points\n";
	--energyPoints;
}
