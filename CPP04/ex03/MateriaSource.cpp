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
	/* Copies the Materia passed as a parameter and stores it in memory so it can
	be cloned later. Like the Character, the MateriaSource can know at most 4 Materias.
	They are not necessarily unique */
	size_t i = 0;
	while (memory[i] && i < INV_SIZE)
		i++;
	memory[i] = m;
	std::cout << &m << std::endl;
	std::cout << memory[i] << std::endl;
/* 	for (size_t i = 0; i < INV_SIZE; i++)
	{
		if (memory[i])
			continue;
		memory[i] = m;
		std::cout << &m << std::endl;
		std::cout << &memory[i] << std::endl;
	} */
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	/* Returns a new Materia. The latter is a copy of the Materia previously
	learned by the MateriaSource whose type equals the one passed as parameter.
	Returns 0 if the type is unknown. */
	for (size_t i = 0; i < INV_SIZE; i++)
	{
		if (memory[i] && memory[i]->getType() == type)
			return (memory[i]->clone());
	}
	return (0);
}
