#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main(void)
{
	Zombie *allocated = newZombie("Ruperto");
	randomChump("Guadalberto");
	delete allocated;
	return (0);
}
