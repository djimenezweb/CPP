#include "iter.hpp"
#include <iostream>

int duplicate(const int &num)
{
	return num * 2;
}

int triplicate(int &num)
{
	return num * 3;
}

void print_duplicate(const int &num)
{
	std::cout << num * 2 << std::endl;
}

void print_triplicate(int &num)
{
	std::cout << num * 3 << std::endl;
}

void print_string(std::string &str)
{
	std::cout << str << std::endl;
}

int	main()
{
	const size_t size = 8;
	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
	std::string arr_str[] = { "ab", "cd", "efgh", "ij", "klmnop", "qr", "stu", "vwxyz"};

	std::cout << std::endl << "Calling duplicate" << std::endl;
	::iter(arr, size, duplicate);
	
	std::cout << std::endl << "Calling triplicate" << std::endl;
	::iter(arr, size, triplicate);

	std::cout << std::endl << "Calling print_duplicate" << std::endl;
	::iter(arr, size, print_duplicate);
	
	std::cout << std::endl << "Calling print_triplicate" << std::endl;
	::iter(arr, size, print_triplicate);
	
	std::cout << std::endl << "Calling print_string" << std::endl;
	::iter(arr_str, size, print_string);

	return (0);
}
