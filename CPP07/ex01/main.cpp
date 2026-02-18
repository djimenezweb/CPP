#include "iter.hpp"

int duplicate(const int &num)
{
	return num * 2;
}

int triplicate(int &num)
{
	return num * 3;
}

int	main()
{
	size_t size = 8;

	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
	
	::iter(arr, size, duplicate);
	::iter(arr, size, triplicate);

	return (0);
}
