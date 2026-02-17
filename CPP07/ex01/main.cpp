#include "iter.hpp"

int	main()
{
	int size = 8;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	
	::iter<int, int, int>(arr, 8);

	return (0);
}
