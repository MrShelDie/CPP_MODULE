#include <iostream>
#include <climits>

#include "ScavTrap.hpp"

int main() {
	ScavTrap a;
	ScavTrap b("ClapTrap3000");
	ScavTrap c(b);
	
	a = b;


	for (size_t i = 0; i < 51; i++) {
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


	c.guardGate();


	return 0;
}