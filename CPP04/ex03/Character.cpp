#include "Character.hpp"

// Default constructor
Character::Character()
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		inventory[i] = NULL;
	}
	used = new AMateria*[1];
	used[0] = NULL;
}

// Parameterized constructor
Character::Character(std::string name) : name(name)
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		inventory[i] = NULL;
	}
	used = new AMateria*[1];
	used[0] = NULL;
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
		// TO DO !!! Copy values
	}
	return (*this);
}

// Destructor
Character::~Character()
{
	// Delete used materias
	size_t	used_size = 0;
	while (used[used_size] != NULL)
		used_size++;
	for (size_t i = 0; i < used_size; i++)
	{
		std::cout << "Deleting pointer: " << used[i] << std::endl;
		delete used[i];
	}
	delete[] used;

	// Delete inventory
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
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
			std::cout << "Equip " << m->getType() << " in inventory slot " << i << std::endl;
			break;
		}
		else
			i++;
	}
	print_inventory();
}

// Unequip
void Character::unequip(int idx)
{
	if (idx < 0 && idx > INV_SIZE && !inventory[idx])
		return ;
	std::cout << "Unequip " << inventory[idx]->getType() << " from slot " << idx
			  << ". Pointer to be deleted: " << inventory[idx] << std::endl;

	size_t	used_size = 0;
	while (used[used_size])
		used_size++;
	AMateria **new_arr = new AMateria*[used_size + 2];
	for (size_t i = 0; i < used_size + 1; i++)
	{
		new_arr[i] = used[i];
	}
	new_arr[used_size] = inventory[idx];
	new_arr[used_size + 1] = NULL;
	delete[] used; // ???
	used = new_arr;
	inventory[idx] = NULL;
	print_inventory();
}

// Use
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= INV_SIZE && inventory[idx])
	{
		inventory[idx]->use(target);
	}
}

// Display inventory
void Character::print_inventory()
{
	size_t i = 0;
	std::cout << "╔═══════════════════╗" << std::endl;
	std::cout << "║ I N V E N T O R Y ║" << std::endl;
	std::cout << "╠════╦════╦════╦════╣" << std::endl;
	while (i < INV_SIZE)
	{
		if (inventory[i] == NULL)
			std::cout << "║    ";
		else if (inventory[i]->getType() == "ice")
			std::cout << "║ 🧊 ";
		else if (inventory[i]->getType() == "cure")
			std::cout << "║ 💊 ";
		i++;
	}
	std::cout << "║" << std::endl;
	std::cout << "╚════╩════╩════╩════╝" << std::endl;
}
