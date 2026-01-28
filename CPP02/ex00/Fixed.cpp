#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : value(0)
{
	std::cout << DEF_CONSTR << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << CPY_CONSTR << std::endl;
	//*this = other; // Works by calling copy assignment operator
	value = other.getRawBits();
}

// Copy assignment operator overload `=`
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << CPY_ASSIGN << std::endl;
	if (this != &other)
	{
		value = other.getRawBits();
	}
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << DESTRUCTOR << std::endl;
}

// Get `value` as integer
int Fixed::getRawBits(void) const
{
	std::cout << GETRAWBITS << std::endl;
	return (value);
}

// Set `value`
void Fixed::setRawBits(int const raw)
{
	value = raw;
}
