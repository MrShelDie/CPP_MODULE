#pragma once
#ifndef __CLAP_TRAP_H__
#define __CLAP_TRAP_H__

#include <string>

class ClapTrap {

public:

	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& other);

	const std::string& getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);


private:

	void init();

	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

};

#endif