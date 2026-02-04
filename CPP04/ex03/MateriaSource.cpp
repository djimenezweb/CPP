#include "MateriaSource.hpp"

// Default constructor
MateriaSource::MateriaSource() {}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource &other) {}

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

void MateriaSource::learnMateria(AMateria*)
{
	/* Copies the Materia passed as a parameter and stores it in memory so it can
	be cloned later. Like the Character, the MateriaSource can know at most 4 Materias.
	They are not necessarily unique */
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	/* Returns a new Materia. The latter is a copy of the Materia previously
	learned by the MateriaSource whose type equals the one passed as parameter.
	Returns 0 if the type is unknown. */
}
