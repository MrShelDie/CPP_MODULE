#pragma once
#ifndef __DIAMOND_TRAP_H__
#define __DIAMOND_TRAP_H__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

public:

	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap();

	DiamondTrap& operator=(const DiamondTrap& other);

	using ScavTrap::attack;
	void whoAmI() const;


private:

	std::string name;

};

#endif