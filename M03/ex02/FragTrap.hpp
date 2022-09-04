#pragma once
#ifndef __FRAG_TRAP_H__
#define __FRAG_TRAP_H__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	~FragTrap();

	void attack(const std::string& target);
	void highFivesGuys();

};

#endif