#include "HumanB.hpp"

HumanB::HumanB(std::string n)
{
	this->name = n;
	this->weapon = NULL;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->weapon = &w;
}

void	HumanB::attack()
{
	if (weapon == NULL)
		std::cout	<< this->name << " peacefully surrenders" << std::endl;
	else
	{
		std::cout	<< this->name << " attacks with their "
					<< weapon->getType() << std::endl;
	}
}
