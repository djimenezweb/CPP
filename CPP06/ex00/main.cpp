#include <iostream>
#include "ScalarConverter.hpp"

/* The following rule applies to the entire module and is mandatory.
For each exercise, type conversion must be handled using a specific type of casting.
Your choice will be reviewed during the defense. */

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error. Correct usage: " << argv[0] << " <arg>" << std::endl;
		 return (1);
	}

	ScalarConverter::convert(argv[1]);

	std::cout << std::endl << "Examples: " << std::endl;
	ScalarConverter::convert("0");
	ScalarConverter::convert("123");
	ScalarConverter::convert("-33");
	ScalarConverter::convert("+33");

	ScalarConverter::convert("n");
	ScalarConverter::convert("c");
	
	ScalarConverter::convert("-4.2f");
	ScalarConverter::convert("42.0f");
	ScalarConverter::convert(".5f");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("nanf");

	ScalarConverter::convert("11.666");
	ScalarConverter::convert(".5");
	ScalarConverter::convert("0.0");
	ScalarConverter::convert("-4.2");
	ScalarConverter::convert("4.2");

	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("nan");

	std::cout << std::endl << "Invalid examples: " << std::endl;
	ScalarConverter::convert("n.an");
	ScalarConverter::convert("13.an");
	ScalarConverter::convert("(?)");
	ScalarConverter::convert("++33");
	ScalarConverter::convert("123.");
	ScalarConverter::convert("+");
	ScalarConverter::convert("42.0z");
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
