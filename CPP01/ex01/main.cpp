#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int N = 6;
	Zombie	*horde = zombieHorde(N, "Segismundo");

	for (int i = 0; i < N; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
}
