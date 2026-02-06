#include "Character.hpp"

// Default constructor
Character::Character()
{
	std::cout << "Character default constr." << std::endl;
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
	std::cout << "Character param constr.: " << name << std::endl;
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
	std::cout << "Character copy constr." << std::endl;
	name = other.name;
	delete_inventory();
	delete_used();
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		inventory[i] = other.inventory[i]->clone();
	}
	size_t	used_size = 0;
	while (other.used[used_size] != NULL)
		used_size++;
	used = new AMateria*[used_size + 1];
	for (size_t i = 0; i < used_size; i++)
	{
		used[i] = other.used[i]->clone();
	}
	used[used_size + 1] = NULL;
}

// Copy assignment operator overload `=`
Character &Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment" << std::endl;
	if (this != &other)
	{
		name = other.name;
		delete_inventory();
		delete_used();
		for (size_t i = 0; i < INV_SIZE; i++)
		{
			inventory[i] = other.inventory[i]->clone();
		}
		size_t	used_size = 0;
		while (other.used[used_size] != NULL)
			used_size++;
		used = new AMateria*[used_size + 1];
		for (size_t i = 0; i < used_size; i++)
		{
			used[i] = other.used[i]->clone();
		}
		used[used_size + 1] = NULL;
	}
	return (*this);
}

// Delete inventory
void Character::delete_inventory()
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

// Delete used materias
void Character::delete_used()
{
	size_t	used_size = 0;
	while (used[used_size] != NULL)
		used_size++;
	for (size_t i = 0; i < used_size; i++)
	{
		std::cout << "Deleting pointer: " << used[i] << std::endl;
		delete used[i];
		used[i] = NULL;
	}
	delete[] used;
}

// Destructor
Character::~Character()
{
	delete_used();
	delete_inventory();
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
