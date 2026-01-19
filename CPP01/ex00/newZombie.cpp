#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie	*z;
	
	z = new Zombie(name);

	if (z == NULL)
		return (NULL);

	z->announce();
	return (z);
}
