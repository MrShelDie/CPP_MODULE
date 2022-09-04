#include <iostream>
#include <climits>

#include "FragTrap.hpp"

int main() {
	FragTrap a;
	FragTrap b("FragTrap3000");
	FragTrap c(b);
	
	a = b;

	unsigned int ePoints = a.getEnergyPoints();
	for (size_t i = 0; i < ePoints + 1; i++) {
		std::cout << i << ": ";
		a.attack("FragTrap3000");
	}
	std::cout << "\n";


	std::cout << "Frag " << b.getName() << " has " << b.getHitPoints() << " hp\n";
	b.takeDamage(1);
	std::cout << "Frag " << b.getName() << " has " << b.getHitPoints() << " hp\n";
	b.takeDamage(UINT_MAX);
	std::cout << "Frag " << b.getName() << " has " << b.getHitPoints() << " hp\n";


	std::cout << "Frag " << c.getName() << " has " << c.getHitPoints() << " hp\n";
	c.beRepaired(1);
	std::cout << "Frag " << c.getName() << " has " << c.getHitPoints() << " hp\n";
	c.beRepaired(UINT_MAX);
	std::cout << "Frag " << c.getName() << " has " << c.getHitPoints() << " hp\n";


	c.highFivesGuys();


	return 0;
}