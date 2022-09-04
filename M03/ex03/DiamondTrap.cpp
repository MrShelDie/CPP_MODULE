#include <iostream>

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap() {

}

DiamondTrap::DiamondTrap(const std::string& name) {

}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	// TODO ClapTrap::operator=(other);
	std::cout << "FragTrap: " << name << " assigned with operator\n";
	return *this;
}