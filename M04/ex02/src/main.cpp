#include <iostream>

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const size_t NB_ANIMALS = 4;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;

	std::cout << "----------------------\n";

	AAnimal* animals[NB_ANIMALS];

	size_t k = 0;
	for (; k < NB_ANIMALS / 2; ++k)
		animals[k] = new Cat();
	for (; k < NB_ANIMALS; ++k)
		animals[k] = new Dog();

	std::cout << "----------------------\n";

	for (k = 0; k < NB_ANIMALS; ++k)
		delete animals[k];

	std::cout << "----------------------\n";

	Cat catA;
	Cat catB;

	catA.getBrain()->ideas[42] = "new idea!!!";
	catB.getBrain()->ideas[42] = "no idea((0(";

	std::cout << "catA idea42: " << catA.getBrain()->ideas[42] << "\n";
	std::cout << "catB idea42: " << catB.getBrain()->ideas[42] << "\n";

	std::cout << catA.getBrain() << "\n";
	std::cout << catB.getBrain() << "\n";

	catB = catA;

	std::cout << catA.getBrain() << "\n";
	std::cout << catB.getBrain() << "\n";

	std::cout << "catA idea42: " << catA.getBrain()->ideas[42] << "\n";
	std::cout << "catB idea42: " << catB.getBrain()->ideas[42] << "\n";

	return 0;
}