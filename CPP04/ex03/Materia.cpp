#include "Materia.hpp"

// Default constructor
AMateria::AMateria() {}

// Parameterized constructor
AMateria::AMateria(std::string const &type) : type(type) {}

// Copy constructor
AMateria::AMateria(const AMateria &other)
{
	type = other.type;
}

// Copy assignment operator overload `=`
AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

// Destructor
AMateria::~AMateria()
{
	// Delete allocated memory
}

// Getter
std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{

}
