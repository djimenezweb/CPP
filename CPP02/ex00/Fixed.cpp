#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	std::cout << DEF_CONSTR << std::endl;
	value = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << CPY_CONSTR << std::endl;
	value = other.value;
}

// Copy assignment operator overload `=`
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << CPY_ASSIGN << std::endl;
	if (this != &other)
	{
		value = other.value;
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
