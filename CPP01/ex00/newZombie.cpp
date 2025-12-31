#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie	*z;
	
	z = new Zombie(name);

	if (z == nullptr)
		return (nullptr);

	z->announce();
	return (z);
}
