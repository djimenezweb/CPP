#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// Custom tests

/* 	if (a > b)
		std::cout << "a is greater than b" << std::endl;
	else
		std::cout << "b is greater than a" << std::endl;

	if (a >= b)
		std::cout << "a is greater or equals than b" << std::endl;
	else
		std::cout << "b is greater or equals than a" << std::endl;

	if (a < b)
		std::cout << "a is smaller than b" << std::endl;
	else
		std::cout << "b is smaller than a" << std::endl;
	
	if (a <= b)
		std::cout << "a is smaller or equals than b" << std::endl;
	else
		std::cout << "b is smaller or equals than a" << std::endl;
	
	if (a == b)
		std::cout << "a is equals to b" << std::endl;
	else
		std::cout << "a is not equals to b" << std::endl;

	if (a != b)
		std::cout << "a is not equals to b" << std::endl;
	else
		std::cout << "a is equals to b" << std::endl;

	Fixed c(Fixed(1.5f) + Fixed(1.5f));
	std::cout << c << std::endl;
	std::cout << --c << std::endl;
	std::cout << c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl; */

	return (0);
}
