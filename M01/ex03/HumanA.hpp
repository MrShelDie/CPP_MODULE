#pragma once
#ifndef __HUMAN_A__
#define __HUMAN_A__

#include <string>

#include "Weapon.hpp"


class HumanA {

public:

	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();

	void attack();


private:

	Weapon& weapon;
	std::string name;	

};

#endif