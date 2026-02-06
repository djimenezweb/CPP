#include "Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria("cure")
{
	std::cout << "Cure copy constructor" << std::endl;
	(void)other;
}

// Copy assignment operator overload `=`
Cure &Cure::operator=(const Cure &other)
{
	std::cout << "Cure copy assignment" << std::endl;
	(void)other;
	return (*this);
}

// Destructor
Cure::~Cure()
{
	std::cout << "Cure destructor" << std::endl;
}

// Clone
AMateria* Cure::clone() const
{
	Cure *p = new Cure();
	return (p);
}

// Use
void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
