#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// Default constructor
ScavTrap::ScavTrap()
{
	name = "undefined";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "Unnamed ScavTrap created" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(std::string set_name) : ClapTrap(set_name)
{
	name = set_name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap " << name << " copied via Copy constructor" << std::endl;
}

// Copy assignment operator overload `=`
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name = other.getName();
		hit_points = other.getHitPoints();
		energy_points = other.getEnergyPoints();
		attack_damage = other.getAttackDamage();
	}
	std::cout << "ScavTrap " << name << " copied via Copy assignment operator" << std::endl;
	return (*this);
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destroyed" << std::endl;
}

// Actions

void ScavTrap::attack(const std::string &target)
{
	if (getHitPoints() == 0)
		std::cout << "ScavTrap " << name << " is dead and doesn't attack" << std::endl;
	else if (getEnergyPoints() == 0)
		std::cout << "ScavTrap " << name << " has no energy to attack " << target << " and doesn't cause any damage" << std::endl;
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << name << " attacks " << target << " causing " << getAttackDamage() << " points of damage" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	if (getHitPoints() == 0)
		std::cout << "ScavTrap " << name << " is dead and can't be in Gate keeper mode" << std::endl;
	else
		std::cout << "ScavTrap " << name << " is in Gate keeper mode" << std::endl;
}
