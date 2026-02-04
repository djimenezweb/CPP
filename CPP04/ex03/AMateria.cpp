#include "AMateria.hpp"

// Default constructor
AMateria::AMateria() {}

// Copy constructor
AMateria::AMateria(const AMateria &other) {}

// Copy assignment operator overload `=`
AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		// Copy values
	}
	return (*this);
}

// Destructor
AMateria::~AMateria()
{
	// Delete allocated memory
}
