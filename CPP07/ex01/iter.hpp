#ifndef ITER_HPP
# define ITER_HPP

# include <stddef.h>

template <typename T1, typename T2>
void	iter(T1 *arr, const size_t size, T2 func)
{
	for (size_t i = 0; i < size; i++)
		func(arr[i]);
}

#endif
