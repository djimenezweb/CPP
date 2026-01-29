#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : value(0)
{
	std::cout << DEF_CONSTR << std::endl;
}

// Constructor (int)
Fixed::Fixed(const int int_value)
{
	std::cout << INT_CONSTR << std::endl;
	value = int_value << Fixed::fr_bits;
}

// Constructor (float)
// Take a float number and save it as fixed point
Fixed::Fixed(const float float_value)
{
	std::cout << FLT_CONSTR << std::endl;

	int	int_part = static_cast<int>(roundf(float_value));
	int	fractional_part = roundf((float_value - int_part) * 8);
	std::cout << "int_part of float_value: " << int_part << std::endl;
	std::cout << "fr_part of float_value: " << fractional_part << std::endl;

	value = static_cast<int>(roundf(float_value * (1 << Fixed::fr_bits)));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << CPY_CONSTR << std::endl;
	*this = other;
	//value = other.value;
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

// Insertion operator overload `<<`
std::ostream &operator<<(std::ostream &output, const Fixed &other)
{
	output << other.toFloat();
	return (output);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << DESTRUCTOR << std::endl;
	value = 0;
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

// Return `value` as a float number
float Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << Fixed::fr_bits));
}

// Return `value` as an integer ommitting decimal part
int Fixed::toInt(void) const
{
	return (value >> Fixed::fr_bits);
}
