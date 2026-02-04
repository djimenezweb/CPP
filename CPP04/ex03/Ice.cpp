#include "Ice.hpp"

// Default constructor
Ice::Ice() {}

// Copy constructor
Ice::Ice(const Ice &other) {}

// Copy assignment operator overload `=`
Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		// Copy values
	}
	return (*this);
}

// Destructor
Ice::~Ice()
{
	// Delete allocated memory
}
