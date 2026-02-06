#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor" << std::endl;
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		memory[i] = NULL;
	}
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource copy constructor" << std::endl;
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		memory[i] = other.memory[i];
	}
}

// Copy assignment operator overload `=`
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource copy assignment" << std::endl;
	if (this != &other)
	{
		for (size_t i = 0; i < INV_SIZE; i++)
		{
			memory[i] = other.memory[i];
		}
	}
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor" << std::endl;
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		if (memory[i] != NULL)
			delete memory[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		if (memory[i] == NULL)
		{
			memory[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		if (memory[i] == NULL)
			continue;
		if (memory[i]->getType() == type)
			return (memory[i]->clone());
	}
	return (0);
}
