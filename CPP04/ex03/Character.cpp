#include "Character.hpp"

// Default constructor
Character::Character()
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		inventory[i] = NULL;
	}
	AMateria *used[1];
	used[0] = NULL;
	std::cout << "Created unnamed Character" << std::endl;
}

// Parameterized constructor
Character::Character(std::string name) : name(name)
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		inventory[i] = NULL;
	}
	AMateria *used[1];
	used[0] = NULL;
	std::cout << "Created Character " << name << std::endl;
}

// Copy constructor
Character::Character(const Character &other)
{
	// TO DO !!!
	(void)other;
}

/* Any copy (using copy constructor or copy assignment operator)
of a Character must be deep. During copy, the Materias of a Character
must be deleted before the new ones are added to their inventory. */

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
	/* The Materias must be deleted when a Character is destroyed. */
}

// Getter
std::string const &Character::getName() const
{
	return (name);
}

// Equip
void Character::equip(AMateria* m)
{
	size_t i = 0;
	while (i < INV_SIZE)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "Equiped " << m->getType() << " in slot " << i << std::endl;
			break;
		}
		else
			i++;
	}
}

// Unequip
void Character::unequip(int idx)
{
	if (idx < 0 && idx > INV_SIZE && !inventory[idx])
		return ;

	size_t	arr_size = 0;
	while (used[arr_size])
		arr_size++;

	AMateria **new_arr = new AMateria*[arr_size + 1];

	for (size_t i = 0; i < arr_size; i++)
	{
		new_arr[i] = used[i];
	}
	
	new_arr[arr_size - 1] = inventory[idx];
	new_arr[arr_size] = NULL;
	delete[] used; // ???
	used = new_arr;
	inventory[idx] = NULL;
}

// Use
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= INV_SIZE && inventory[idx])
	{
		inventory[idx]->use(target);
	}
}
