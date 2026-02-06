#include "Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria("ice")
{
	(void)other;
}

// Copy assignment operator overload `=`
Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	return (*this);
}

// Destructor
Ice::~Ice() {}

// Clone
AMateria* Ice::clone() const
{
	Ice *p = new Ice();
	return (p);
}

// Use
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
