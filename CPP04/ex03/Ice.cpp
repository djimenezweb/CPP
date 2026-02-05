#include "Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {}

// Copy constructor
Ice::Ice(const Ice &other)
{
	// TO DO !!!
	(void)other;
}

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

// Clone
AMateria* Ice::clone() const
{
	Ice	*p = new Ice();
	return (p);
}

// Use
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
