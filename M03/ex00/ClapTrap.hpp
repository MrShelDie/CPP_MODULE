#pragma once
#ifndef __CLAP_TRAP__
#define __CLAP_TRAP__

#include <string>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);


private:

	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

};

#endif