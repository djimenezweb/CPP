#include "Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria("ice")
{
	std::cout << "Ice copy constructor" << std::endl;
	(void)other;
}

// Copy assignment operator overload `=`
Ice &Ice::operator=(const Ice &other)
{
	std::cout << "Ice copy assignment" << std::endl;
	(void)other;
	return (*this);
}

// Destructor
Ice::~Ice()
{
	std::cout << "Ice destructor" << std::endl;
}

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
