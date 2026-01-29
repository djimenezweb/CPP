#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

# define DEF_CONSTR "Default constructor called"
# define INT_CONSTR "Int constructor called"
# define FLT_CONSTR "Float constructor called"
# define DESTRUCTOR "Destructor called"
# define CPY_CONSTR "Copy constructor called"
# define CPY_ASSIGN "Copy assignment operator called"
# define GETRAWBITS "getRawBits member function called"

class Fixed
{
private:
	int value;
	static const int fr_bits = 8;

public:
	Fixed();
	Fixed(const int int_value);
	Fixed(const float float_value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &other);

#endif
