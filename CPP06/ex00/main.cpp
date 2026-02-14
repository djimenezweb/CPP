#include <iostream>
#include "ScalarConverter.hpp"

using std::cout;
using std::cerr;
using std::endl;

/* The following rule applies to the entire module and is mandatory.
For each exercise, type conversion must be handled using a specific type of casting.
Your choice will be reviewed during the defense. */

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		//cerr << "Error. Correct usage: ./convert <arg>" << endl;
		// return (1);
	}

	(void)argv;
	// ScalarConverter::convert(argv[1]);
	ScalarConverter::convert("0");
	cout << "-> 3 (int) (expected)" << endl << endl;
	ScalarConverter::convert("123");
	cout << "-> 3 (int) (expected)" << endl << endl;
	ScalarConverter::convert("-33");
	cout << "-> 3 (int) (expected)" << endl << endl;
	ScalarConverter::convert("11.666");
	cout << "-> 5 (fraction) (expected)" << endl << endl;
	ScalarConverter::convert("42.0f");
	cout << "-> 6 (suffix) (expected)" << endl << endl;
	ScalarConverter::convert("n");
	cout << "-> 1 (char) (expected)" << endl << endl;
	ScalarConverter::convert("nan");
	cout << "-> 7 (invalid) (expected)" << endl << endl;
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
