#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

class A {};

int main()
{
	const size_t NB_ANIMALS = 4;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "----------------------\n";

	Animal* animals[NB_ANIMALS];

	size_t k = 0;
	for (; k < NB_ANIMALS / 2; ++k)
		animals[k] = new Cat();
	for (; k < NB_ANIMALS; ++k)
		animals[k] = new Dog();

	std::cout << "----------------------\n";

	for (k = 0; k < NB_ANIMALS; ++k)
		delete animals[k];

	return 0;
}