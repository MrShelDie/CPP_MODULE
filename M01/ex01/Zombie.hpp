#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <string>

class Zombie {

public:

	Zombie(void);
	Zombie(const std::string& name);
	~Zombie(void);

	void setName(const std::string& name);

	void announce(void);


private:

	std::string name;

};

#endif