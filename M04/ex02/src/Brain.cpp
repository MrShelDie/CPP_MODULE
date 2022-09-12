#include <iostream>

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default contructor is called\n";
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor is called\n";
	*this = other;
}

Brain::~Brain() {
	std::cout << "Brain destructor is called\n";
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator is called\n";
	if (&other != this) {
		for (size_t i = 0; i < NB_IDEAS; ++i)
			ideas[i] = other.ideas[i];
	}
	return *this;
}
