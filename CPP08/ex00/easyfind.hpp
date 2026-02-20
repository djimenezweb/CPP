#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <list>
# include <exception>

template <typename T>
void	easyfind(const T &container, const int num)
{
	if (container.empty())
		throw (std::runtime_error("Container is empty"));

	typename T::const_iterator it = container.begin();

	while (it != container.end())
	{
		if (*it == num)
		{
			std::cout << "Found number: " << *it << " == " << num << std::endl;
			return;
		}
		it++;
	}
	throw (std::runtime_error("Value wasn't found"));
}

#endif
