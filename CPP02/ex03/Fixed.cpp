#include "Fixed.hpp"

// Default constructor
Fixed::Fixed()
{
	value = 0;
}

// Constructor (int)
Fixed::Fixed(const int set_value)
{
	value = set_value << Fixed::fr_bits;
}

// Constructor (float)
Fixed::Fixed(const float set_value)
{
	value = static_cast<int>(roundf(set_value * (1 << Fixed::fr_bits)));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

// Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		value = other.value;
	}
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	value = 0;
}

// Getter
int Fixed::getRawBits(void) const
{
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

// Insertion operator overload
std::ostream &operator<<(std::ostream &output, const Fixed &other)
{
	output << other.toFloat();
	return (output);
}

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

Fixed Fixed::abs(const Fixed &other)
{
	if (other.toFloat() < 0.0)
		return (Fixed(other) * Fixed(-1));
	return (other);
}
