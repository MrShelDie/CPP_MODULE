#include <string>
#include <iostream>

#include "convert.hpp"

Literal convert(const std::string& arg)
{

}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " literal\n";
		return 1;
	}

	std::string arg = std::string(argv[1]);


	return 0;
}
