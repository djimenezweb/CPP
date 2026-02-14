#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter() {}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

// Copy assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter() {}

// Convert
void ScalarConverter::convert(string str)
{
	cout << "  char: " << str << endl
		 << "   int: " << str << endl
		 << " float: " << str << endl
		 << "double: " << str << endl
		 << endl;
}
