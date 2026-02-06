#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		memory[i] = NULL;
	}
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	// TO DO !!!!!
	(void)other;
}

// Copy assignment operator overload `=`
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		// TO DO !!! Copy values
	}
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		if (memory[i] != NULL)
			delete memory[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	size_t i = 0;
	while (i < INV_SIZE)
	{
		if (memory[i] == NULL)
		{
			memory[i] = m;
			break;
		}
		else
			i++;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	size_t i = 0;
	while (i < INV_SIZE)
	{
		if (memory[i] == NULL)
		{
			i++;
			continue;
		}
		else if (memory[i]->getType() == type)
			return (memory[i]->clone());
		i++;
	}
	return (0);
}
