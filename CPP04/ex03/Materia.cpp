#include "Materia.hpp"

// Default constructor
AMateria::AMateria()
{
	std::cout << "AMateria default constructor" << std::endl;
}

// Parameterized constructor
AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "AMateria parameterized constructor" << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria &other)
{
	std::cout << "AMateria copy constructor" << std::endl;
	type = other.type;
}

// Copy assignment operator overload `=`
AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << "AMateria copy assignment" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

// Destructor
AMateria::~AMateria()
{
	std::cout << "AMateria destructor" << std::endl;
}

// Getter
std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
