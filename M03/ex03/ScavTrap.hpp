#pragma once
#ifndef __SCAV_TRAP_H__
#define __SCAV_TRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

public:

	ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap();

	ScavTrap& operator=(const std::string& other);

	void attack(const std::string& target);
	void guardGate();

};

#endif