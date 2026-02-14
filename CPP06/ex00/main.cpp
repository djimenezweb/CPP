#include <iostream>
#include "ScalarConverter.hpp"

using std::cout;
using std::cerr;
using std::endl;

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cerr << "Error. Correct usage: ./convert <arg>" << endl;
		// return (1);
	}

	(void)argv;
	// ScalarConverter::convert(argv[1]);
	ScalarConverter::convert("0");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("42.0f");
}

/*

./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0

./convert nan
char: impossible
int: impossible
float: nanf
double: nan

./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

*/
