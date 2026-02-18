#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T1, typename T2>
void	iter(T1 *arr, size_t size, T2 func)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << func(arr[i]) << " ";
	}
	std::cout << std::endl;
}

#endif
