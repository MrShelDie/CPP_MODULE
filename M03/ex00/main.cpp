#include <iostream>
#include <climits>

#include "ClapTrap.hpp"


int main() {
	ClapTrap a;
	ClapTrap b("ClapTrap3000");
	ClapTrap c(b);
	
	a = b;


	for (size_t i = 0; i < 11; i++) {
		std::cout << i << ": ";
		a.attack("ClapTrap3000");
	}
	std::cout << "\n";


	std::cout << "Clap " << b.getName() << " has " << b.getHitPoints() << " hp\n";
	b.takeDamage(1);
	std::cout << "Clap " << b.getName() << " has " << b.getHitPoints() << " hp\n";
	b.takeDamage(UINT_MAX);
	std::cout << "Clap " << b.getName() << " has " << b.getHitPoints() << " hp\n";


	std::cout << "Clap " << c.getName() << " has " << c.getHitPoints() << " hp\n";
	c.beRepaired(1);
	std::cout << "Clap " << c.getName() << " has " << c.getHitPoints() << " hp\n";
	c.beRepaired(UINT_MAX);
	std::cout << "Clap " << c.getName() << " has " << c.getHitPoints() << " hp\n";

	return 0;
}