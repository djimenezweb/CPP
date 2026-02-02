#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap()
{
	hit_points = FRAG_HITPTS;
	energy_points = SCAV_ENERGY;
	attack_damage = FRAG_ATTACK;
	std::cout << "Unnamed FragTrap created" << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(std::string set_name) : ClapTrap(set_name)
{
	hit_points = FRAG_HITPTS;
	energy_points = SCAV_ENERGY;
	attack_damage = FRAG_ATTACK;
	std::cout << "FragTrap " << name << " created" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	(void)other;
}

// Copy assignment operator overload `=`
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		// Copy values
	}
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	// Delete allocated memory
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
