#include <list>
#include <vector>
#include <iostream>

#include "easyfind.hpp"

int main()
{
	const size_t SIZE = 5;

	{
		std::vector<int> intv(SIZE);

		for (size_t i = 0; i < SIZE; ++i) {
			intv[i] = i;
			std::cout << intv[i] << " "; 
		}
		
		std::cout << "\n";

		{
			std::vector<int>::iterator it = easyfind(intv, 3);
			*it = 42;
		}

		for (size_t i = 0; i < SIZE; ++i) 
			std::cout << intv[i] << " "; 
		std::cout << "\n";

		try {
			easyfind(intv, 21);	
		} catch (std::exception& e) {
			std::cerr << "21 is not in vector\n";	
		}
	}

	std::cout << "---------------------------------\n";

	{
		std::list<int> intl(SIZE);

		{
			int i = 0;	
			for (std::list<int>::iterator it = intl.begin(); it != intl.end(); ++it) {
				*it = i;
				std::cout << *it << " ";
				++i;	
			}
			std::cout << "\n";
		}

		{
			std::list<int>::iterator it = easyfind(intl, 4);
			*it = 41;
		}
		
		for (std::list<int>::iterator it = intl.begin(); it != intl.end(); ++it) 
			std::cout << *it << " ";
		std::cout << "\n";

		try {
			easyfind(intl, 21);	
		} catch (std::exception& e) {
			std::cerr << "21 is not in list\n";	
		}
	}

	return 0;
}
