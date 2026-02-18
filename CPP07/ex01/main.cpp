#include "iter.hpp"

int duplicate(int &num)
{
	return num * 2;
}

int triplicate(int num)
{
	return num * 3;
}

int	main()
{
	int size = 8;
	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80 };
	const int arr_c[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	
	::iter(arr, size, duplicate);
	::iter(arr_c, size, duplicate);

	::iter(arr, size, triplicate);
	::iter(arr_c, size, triplicate);

	return (0);
}
