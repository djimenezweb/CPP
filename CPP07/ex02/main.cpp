#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 10

int main(int, char**)
{
	Array<int> empty_arr;

	Array<int> numbers(MAX_VAL);
	
	Array<int> numbers_negative(-1);
	
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "Testing copy constructor" << std::endl;
	Array<int> numbers_cpy = numbers;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << numbers[i] << " == " << numbers_cpy[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Testing copy assignment operator" << std::endl;
	Array<int> numbers_assign1(numbers);
	Array<int> numbers_assign2(numbers);
	numbers_assign2[2] = 2222;
	numbers_assign1 = numbers_assign2;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << numbers_assign1[i] << " == " << numbers_assign2[i] << std::endl;
	}
	std::cout << std::endl;

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
		std::cout << "Trying to access array[0]" << std::endl;
		std::cout << numbers[0] << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Trying to access array[-2]" << std::endl;
		std::cout << numbers[-2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		std::cout << "Trying to access array[9999]" << std::endl;
		std::cout << numbers[9999] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		std::cout << "Trying to access array[MAX_VAL]" << std::endl;
		std::cout << numbers[MAX_VAL] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		std::cout << "Trying to access last element via array[array.size() - 1]" << std::endl;
		std::cout << numbers[numbers.size() - 1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	std::cout << std::endl << "Deleting:" << std::endl;
	delete [] mirror;
	return 0;
}
