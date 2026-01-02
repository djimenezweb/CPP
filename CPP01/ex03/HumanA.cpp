#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon w)
{
	this->name = n;
	this->weapon = w;
}

void	HumanA::attack()
{
	std::cout	<< this->name
				<< " attacks with their "
				<< this->weapon.getType()
				<< std::endl;
}
