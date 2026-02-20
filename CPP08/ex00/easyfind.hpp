#ifndef EASYFIND_H
# define EASYFIND_H

# include <iostream>
# include <list>
# include <exception>

template <typename Container>
void	easyfind(Container &container, const int num)
{
	typename Container::iterator it = container.begin();
	if (it == container.end())
		throw (std::runtime_error("Can't find value in an empty list"));

	while (it != container.end())
	{
		if (*it == num)
			return;
		it++;
	}
	throw (std::runtime_error("Value wasn't found"));
}

template <typename Container>
void	easyfind(const Container &container, const int num)
{
	typename Container::const_iterator it = container.begin();
	if (it == container.end())
		throw (std::runtime_error("Can't find value in an empty list (const)"));

	while (it != container.end())
	{
		if (*it == num)
			return;
		it++;
	}
	throw (std::runtime_error("Value wasn't found (const)"));
}

#endif
