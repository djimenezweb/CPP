#include "Fixed.hpp"

// ex00

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

// ex01

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
	int factor = (1 << Fixed::fr_bits);
	value = static_cast<int>(roundf(float_value * factor));
}

// Insertion operator overload `<<`
std::ostream &operator<<(std::ostream &output, const Fixed &other)
{
	output << other.toFloat();
	return (output);
}

// Return `value` as a float number
float Fixed::toFloat(void) const
{
	float factor = (1 << Fixed::fr_bits);
	return (value / factor);
}

// Return integer part of `value` only (ommitting fractional part)
int Fixed::toInt(void) const
{
	return (value >> Fixed::fr_bits);
}

// ex02

// Greater than operator overload
bool Fixed::operator>(const Fixed &right)
{
	if (this->toFloat() > right.toFloat())
		return (true);
	return (false);
}

// Greater or equal than operator overload
bool Fixed::operator>=(const Fixed &right)
{
	if (this->toFloat() >= right.toFloat())
		return (true);
	return (false);
}

// Less than operator overload
bool Fixed::operator<(const Fixed &right)
{
	if (this->toFloat() < right.toFloat())
		return (true);
	return (false);
}

// Less or equal than operator overload
bool Fixed::operator<=(const Fixed &right)
{
	if (this->toFloat() <= right.toFloat())
		return (true);
	return (false);
}

// Equality operator overload
bool Fixed::operator==(const Fixed &right)
{
	if (this->toFloat() == right.toFloat())
		return (true);
	return (false);
}

// Inequality operator overload
bool Fixed::operator!=(const Fixed &right)
{
	if (this->toFloat() != right.toFloat())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &right)
{
	float result;

	result = this->toFloat() + right.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator-(const Fixed &right)
{
	float result;

	result = this->toFloat() - right.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator*(const Fixed &right)
{
	float result;

	result = this->toFloat() * right.toFloat();
	return (Fixed(result));
}

Fixed Fixed::operator/(const Fixed &right)
{
	float result;

	result = this->toFloat() / right.toFloat();
	return (Fixed(result));
}

// pre ++a
Fixed &Fixed::operator++()
{
	value++;
	return (*this);
}

// post a++
Fixed Fixed::operator++(int)
{
	float prev;

	prev = this->toFloat();
	value++;
	return (Fixed(prev));
}

// pre --a
Fixed &Fixed::operator--()
{
	value--;
	return (*this);
}

// post a--
Fixed Fixed::operator--(int)
{
	float prev;

	prev = this->toFloat();
	value--;
	return (Fixed(prev));
}

Fixed &Fixed::min(Fixed &left, Fixed &right)
{
	if (left.toFloat() < right.toFloat())
		return (left);
	return (right);
}

Fixed Fixed::min(const Fixed &left, const Fixed &right)
{
	if (left.toFloat() < right.toFloat())
		return (left);
	return (right);
}

Fixed &Fixed::max(Fixed &left, Fixed &right)
{
	if (left.toFloat() > right.toFloat())
		return (left);
	return (right);
}

Fixed Fixed::max(const Fixed &left, const Fixed &right)
{
	if (left.toFloat() > right.toFloat())
		return (left);
	return (right);
}
