#pragma once
#ifndef __HUMAN_B__
#define __HUMAN_B__

#include <string>

#include "Weapon.hpp"


class HumanB {

public:

	HumanB(const std::string& name);
	~HumanB();

	void setWeapon(Weapon& weapon);

	void attack();


private:

	Weapon* weapon;
	std::string name;	

};

#endif