#ifndef FIXED_H
# define FIXED_H

# include <iostream>

# define DEF_CONSTR "Default constructor called"
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
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
