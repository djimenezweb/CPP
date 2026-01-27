#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "Pre" << std::endl;
	std::cout << "a:   " << a << std::endl;					// 0
	std::cout << "++a: " << ++a << std::endl;				// 0.00390625
	std::cout << "a:   " << a << std::endl;					// 0.00390625
	
	std::cout << std::endl;
	std::cout << "Post" << std::endl;
	std::cout << "a:   " << a << std::endl;					// 0.00390625
	std::cout << "a++: " << a++ << std::endl;				// 0.00390625
	std::cout << "a:   " << a << std::endl;					// 0.0078125	// MAL!!!

	std::cout << std::endl;
	std::cout << "b" << std::endl;
	std::cout << b << std::endl;					// 10.1016
	std::cout << Fixed::max( a, b ) << std::endl;	// 10.1016

	return 0;
}
