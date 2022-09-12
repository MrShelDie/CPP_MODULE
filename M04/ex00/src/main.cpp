#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongAnimal->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	std::cout << "---------------------\n";

	Animal animalA;
	Animal animalB(animalA);
	animalA = animalB;

	std::cout << "---------------------\n";

	Cat catA;
	Cat catB(catA);
	catA = catB;

	std::cout << "---------------------\n";

	Dog dogA;
	Dog dogB(dogA);
	dogA = dogB;

	std::cout << "---------------------\n";

	WrongAnimal wroingAnimalA;
	WrongAnimal wrongAnimalB(wroingAnimalA);
	wroingAnimalA = wrongAnimalB;

	std::cout << "---------------------\n";

	WrongCat wrongCatA;
	WrongCat wrongCatB(wrongCatA);
	wrongCatA = wrongCatB;

	std::cout << "---------------------\n";

	return 0;
}