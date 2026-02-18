#include <iostream>

template <typename T1, typename T2, typename T3>
void	iter(T1 arr[], const T2 size, T3 &func)
{
	size_t max_size = static_cast<size_t>(size);
	for (size_t i = 0; i < max_size; i++)
	{
		std::cout << func(const_cast<T2&>(arr[i])) << " ";
	}
	std::cout << std::endl;
}
