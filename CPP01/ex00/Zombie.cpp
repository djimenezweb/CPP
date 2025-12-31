#include "Zombie.hpp"

Zombie::Zombie(std::string set_name) : name(set_name) {}

Zombie::~Zombie()
{
	std::cout << this->name << " was destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


