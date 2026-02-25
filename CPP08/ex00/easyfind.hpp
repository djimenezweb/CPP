#ifndef EASYFIND_H
# define EASYFIND_H

# include <exception>
# include <algorithm>

template <typename T>
void easyfind(const T &container, const int num)
{
	if (std::find(container.begin(), container.end(), num) == container.end())
		throw (std::runtime_error("Value wasn't found"));
}

#endif
