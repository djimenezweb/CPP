#include "FragTrap.hpp"
#include "ClapTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap()
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "Unnamed FragTrap created" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(std::string set_name) : ClapTrap(set_name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " created" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << name << " copied via Copy constructor" << std::endl;
}

// Copy assignment operator overload `=`
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	std::cout << "FragTrap " << name << " copied via Copy assignment operator" << std::endl;
	return (*this);
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " destroyed" << std::endl;
}

// Actions

void FragTrap::attack(const std::string &target)
{
	if (getHitPoints() == 0)
		std::cout << "FragTrap " << name << " is dead and doesn't attack" << std::endl;
	else if (getEnergyPoints() == 0)
		std::cout << "FragTrap " << name << " has no energy to attack " << target << " and doesn't cause any damage" << std::endl;
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "FragTrap " << name << " attacks " << target << " causing " << getAttackDamage() << " points of damage" << std::endl;
	}
}

void	FragTrap::highFivesGuys()
{
	if (getHitPoints() == 0)
		std::cout << "FragTrap " << name << " is dead and can't high five" << std::endl;
	else
		std::cout << "FragTrap " << name << " high fives guys" << std::endl;
}
