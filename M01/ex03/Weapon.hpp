#pragma once
#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <string>

class Weapon {

public:

	Weapon();
	Weapon(const std::string& type);
	~Weapon();

	const std::string& getType() const;
	void setType(const std::string& type);


private:

	std::string type;

};

#endif