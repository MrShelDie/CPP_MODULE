#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750

int main()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);

		for (int i = 0; i < MAX_VAL; ++i)
		{
			if (tmp[i] != numbers[i])
			{
				std::cerr << "didn't copy the same value!!" << std::endl;
				return 1;
			}
		}

		tmp[0] = numbers[0] + 1;
		if (tmp[0] == numbers[0])
		{
            std::cerr << "array copied by pointer" << std::endl;
            return 1;
		}
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ". Index: -2" << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << ". Index: " << MAX_VAL<< '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

	{
		Array<int> tmp(MAX_VAL);
		tmp = numbers; 

		for (int i = 0; i < MAX_VAL; ++i)
		{
			tmp[0]++;
			if (tmp[i] != numbers[i])
			{
				std::cerr << "didn't copy the same value!!" << std::endl;
				return 1;
			}
		}
	}

    delete [] mirror;
    return 0;
}
