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
