#include "Zombie.hpp"
#include <array>
#include <vector>

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (nullptr);

	Zombie *arr = new Zombie[N];

	return (arr);
}