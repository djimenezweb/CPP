#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	energy_points = SCAV_ENERGY;
	std::cout << "Unnamed DiamondTrap created" << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(std::string set_name) : ClapTrap(set_name + "_clap_name"), ScavTrap(set_name + "_clap_name"), FragTrap(set_name + "_clap_name")
{
	name = set_name;
	energy_points = SCAV_ENERGY;
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap " << name << " copied via Copy constructor" << std::endl;
}

// Copy assignment operator overload `=`
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " destroyed" << std::endl;
}

// Actions

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << std::endl
			  << "   ClapTrap name: " << ClapTrap::name << std::endl;
}
