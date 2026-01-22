/* From now on, all your classes must be designed in the Orthodox Canonical Form,
unless explicitly stated otherwise. They will then implement the four required member
functions below:

• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor

fixed-point numbers:
http://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html
http://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html
http://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html

https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html

*/

#include "Fixed.hpp"

const int Fixed::fr_bits = 8;

// Default constructor
Fixed::Fixed()
{
	std::cout << DEF_CONSTR << std::endl;
	value = 0;
}

// Copy constructor
Fixed::Fixed(const Fixed& rhs)
{
	std::cout << CPY_CONSTR << std::endl;
	value = rhs.getRawBits();
}

// Copy assignment operator overload
void Fixed::operator=(const Fixed& rhs)
{
	std::cout << CPY_ASSIGN << std::endl;
	if (this == &rhs)
		return;
	value = rhs.getRawBits();
}

// Destructor
Fixed::~Fixed()
{
	std::cout << DESTRUCTOR << std::endl;
	value = 0;
}

int Fixed::getRawBits(void) const
{
	std::cout << GETRAWBITS << std::endl;
	return (value);
}

int Fixed::setRawBits(int const raw)
{
	value = raw;
	return (value);
}
