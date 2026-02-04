#include "Character.hpp"

// Default constructor
Character::Character()
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		inventory[i] = NULL;
	}
}

// Parameterized constructor
Character::Character(std::string name) : name(name)
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		inventory[i] = NULL;
	}
}

// Copy constructor
Character::Character(const Character &other) {}

// Copy assignment operator overload `=`
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		// Copy values
	}
	return (*this);
}

// Destructor
Character::~Character()
{
	// Delete allocated memory
}

// Getter
std::string const &Character::getName() const
{
	return (name);
}

// Equip
void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		if (!inventory[i])
			continue;
		inventory[i] = m;
	}
}

// Unequip
void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= INV_SIZE && !inventory[idx])
	{
		// SAVE address before calling unequip
		inventory[idx] = NULL; //????
	}
}

// Use
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= INV_SIZE && !inventory[idx])
		inventory[idx]->use(target);
}
