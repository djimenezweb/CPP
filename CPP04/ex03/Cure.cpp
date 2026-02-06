#include "Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure") {}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria("cure")
{
	(void)other;
}

// Copy assignment operator overload `=`
Cure &Cure::operator=(const Cure &other)
{
	(void)other;
	return (*this);
}

// Destructor
Cure::~Cure() {}

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
