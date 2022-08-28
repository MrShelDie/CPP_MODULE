#include <iostream>

#include "HumanB.hpp"


HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {

}

HumanB::~HumanB() {

}

void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() {
	std::cout << name << " attacks with their " << weapon->getType() << "\n";
}