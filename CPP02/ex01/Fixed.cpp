#include "Fixed.hpp"

const int Fixed::fr_bits = 8;

// Default constructor
Fixed::Fixed()
{
	std::cout << DEF_CONSTR << std::endl;
	value = 0;
}

// Constructor (int)
Fixed::Fixed(const int set_value)
{
	std::cout << INT_CONSTR << std::endl;
	value = set_value << Fixed::fr_bits;
}

// Constructor (float)
Fixed::Fixed(const float set_value)
{
	std::cout << FLT_CONSTR << std::endl;
	value = static_cast<int>(roundf(set_value * (1 << Fixed::fr_bits)));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << CPY_CONSTR << std::endl;
	*this = other;
	//value = other.value;
}

// Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << CPY_ASSIGN << std::endl;
	if (this != &other)
	{
		value = other.value;
	}
	return (*this);
}

// Insertion operator overload
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

// Getter
int Fixed::getRawBits(void) const
{
	std::cout << GETRAWBITS << std::endl;
	return (value);
}

// Setter
void Fixed::setRawBits(int const raw)
{
	value = raw;
}

// Convert integer to float
float Fixed::toFloat(void) const
{
	return (static_cast<float>(value) / (1 << Fixed::fr_bits));
}

// Convert float to integer
int Fixed::toInt(void) const
{
	return (value >> Fixed::fr_bits);
}
