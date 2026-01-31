#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap()
{
	name = "undefined";
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(std::string set_name)
{
	name = set_name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap " << name << " copied" << std::endl;
}

// Copy assignment operator overload `=`
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.getName();
		hit_points = other.getHitPoints();
		energy_points = other.getEnergyPoints();
		attack_damage = other.getAttackDamage();
	}
	std::cout << "ClapTrap " << name << " copied" << std::endl;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

std::string	ClapTrap::getName() const
{
	return (name);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (hit_points);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (energy_points);
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (attack_damage);
}

void	ClapTrap::setName(std::string set_name)
{
	name = set_name;
}

void	ClapTrap::setHitPoints(unsigned int value)
{
	hit_points = value;
}

void	ClapTrap::setEnergyPoints(unsigned int value)
{
	energy_points = value;
}

void	ClapTrap::setAttackDamage(unsigned int value)
{
	attack_damage = value;
}

void ClapTrap::attack(const std::string &target)
{
	if (getEnergyPoints() == 0)
	{
		std::cout << "ClapTrap " << name << " is unable to attack " << target << " and doesn't cause any damage" << std::endl;
	}
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ClapTrap " << name << " attacks " << target << " causing " << getAttackDamage() << " points of damage" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > getHitPoints())
		setHitPoints(0);
	else
		setHitPoints(getHitPoints() - amount);
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (getEnergyPoints() == 0)
	{
		std::cout << "ClapTrap " << name << " is unable to repair itself" << std::endl;
	}
	else
	{
		setHitPoints(getHitPoints() + 1);
		std::cout << "ClapTrap " << name << " gains " << amount << " hit points" << std::endl;
	}
}

