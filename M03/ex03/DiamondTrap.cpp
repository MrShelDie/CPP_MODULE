#include <iostream>

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : DiamondTrap() {

}

DiamondTrap::DiamondTrap(const std::string& name) {

}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	// ClapTrap::operator=(other);
	std::cout << "DiamondTrap: " << name << " assigned with operator\n";
	return *this;
}