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

void p_duplicate(const int &num)
{
	std::cout << num * 2 << std::endl;
}

void p_triplicate(int &num)
{
	std::cout << num * 2 << std::endl;
}

int	main()
{
	const size_t size = 8;

	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
	

	std::cout << std::endl << "Calling duplicate" << std::endl;
	::iter(arr, size, duplicate);
	std::cout << std::endl << "Calling triplicate" << std::endl;
	::iter(arr, size, triplicate);

	std::cout << std::endl << "Calling p_duplicate" << std::endl;
	::iter(arr, size, p_duplicate);
	std::cout << std::endl << "Calling p_triplicate" << std::endl;
	::iter(arr, size, p_triplicate);

	return (0);
}
