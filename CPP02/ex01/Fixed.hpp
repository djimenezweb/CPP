#ifndef FIXED_H
#define FIXED_H

#include <iostream>

#define DEF_CONSTR "Default constructor called"
#define INT_CONSTR "Int constructor called"
#define FLT_CONSTR "Float constructor called"
#define DESTRUCTOR "Destructor called"
#define CPY_CONSTR "Copy constructor called"
#define CPY_ASSIGN "Copy assignment operator called"
#define GETRAWBITS "getRawBits member function called"

class Fixed
{
private:
	int value;
	static const int fr_bits;

public:
	Fixed(); // default constructor
	Fixed(const int value);
	Fixed(const Fixed &other); // copy constructor
	//void operator=(const Fixed &other); // copy assignment operator overload
	Fixed &operator=(const Fixed &other);  // copy assignment operator overload
	Fixed &operator<<(const Fixed &other); // copy insertion operator overload
	~Fixed();							   // destructor

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

/*
int getRawBits(void) const	-> It will be called on const objets. It will NOT modify the objet
int getRawBits(void)		-> Cannot be called on const objects. It may modify the object
*/

#endif