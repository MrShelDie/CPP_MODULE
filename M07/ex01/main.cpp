#include <string>
#include <iostream>

#include "iter.hpp"

void increment(int& num) {
	++num;
}

void appendPrefix(std::string& str) {
	str = "ft_" + str;
}

int main() {
	const size_t SIZE = 5;

	{
		int intArr[SIZE];

		for (size_t i = 0; i < SIZE; ++i) {
			intArr[i] = 0;
			std::cout << intArr[i] << " ";
		}
		std::cout << "\n";

		iter(intArr, SIZE, &increment);

		for (size_t i = 0; i < SIZE; ++i) {
			std::cout << intArr[i] << " ";
		}
		std::cout << "\n";
	}

	std::cout << "-----------------------------\n";

	{
		std::string strs[SIZE];

		for (size_t i = 0; i < SIZE; ++i) {
			strs[i] = "a";
			std::cout << strs[i] << " ";
		}
		std::cout << "\n";

		iter(strs, SIZE, &appendPrefix);

		for (size_t i = 0; i < SIZE; ++i) {
			std::cout << strs[i] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}
