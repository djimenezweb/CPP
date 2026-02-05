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
		// Copy values
	}
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource()
{
	// Delete allocated memory
}

void MateriaSource::learnMateria(AMateria *m)
{
	std::cout << "Learning Materia " << m->getType() << std::endl;
	/* Copies the Materia passed as a parameter and stores it in memory so it can
	be cloned later. Like the Character, the MateriaSource can know at most 4 Materias.
	They are not necessarily unique */
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
	size_t j = 0;
	while (j < INV_SIZE)
	{
		if (memory[j] == NULL)
			std::cout << "| NULL ";
		else
			std::cout << "| " << memory[j]->getType() << " ";
		j++;
	}
	std::cout << "|" << std::endl;

	std::cout << "Creating Materia " << type << std::endl;
	/* Returns a new Materia. The latter is a copy of the Materia previously
	learned by the MateriaSource whose type equals the one passed as parameter.
	Returns 0 if the type is unknown. */
	size_t i = 0;
	while (i < INV_SIZE)
	{
		if (memory[i] == NULL)
			return (0);
		else if (memory[i]->getType() == type)
			return (memory[i]->clone());
		i++;
	}
	return (0);
}
