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
	cout << str << endl;
/* 	cout << "  char: " << str << endl
		 << "   int: " << str << endl
		 << " float: " << str << endl
		 << "double: " << str << endl; */
	size_t result = detect(str);
	cout << "-> " << result << endl;
}

// Return type of the passed literal string
size_t ScalarConverter::detect(string &str)
{
	state state = S_START;
	size_t i = 0;
	while (i < str.length())
	{
		char c = str[i];
		switch (state)
		{
			case S_START:
				if (c == '-' || c == '+')
					state = S_SIGN;
				else if (std::isalpha(c))
					state = S_CHAR;
				else if (std::isdigit(c))
					state = S_INTEGER;
				else
					state = S_INVALID;
				break;

			case S_CHAR:
					state = S_INVALID;
				break;

			case S_SIGN:
				if (std::isdigit(c))
					state = S_INTEGER;
				else
					state = S_INVALID;
				break;

			case S_INTEGER:
				if (std::isdigit(c))
					state = S_INTEGER;
				else if (c == '.')
					state = S_DOT;
				else
					state = S_INVALID;
				break;

			case S_DOT:
				if (std::isdigit(c))
					state = S_FRACTION;
				else
					state = S_INVALID;
				break;

			case S_FRACTION:
				if (std::isdigit(c))
					state = S_FRACTION;
				else if (c == 'f')
					state = S_SUFFIX;
				else
					state = S_INVALID;
				break;

			case S_SUFFIX:
				if (c == '\0')
					state = S_SUFFIX;
				else
					state = S_INVALID;
				break;
			
			case S_INVALID:
				return (S_INVALID);
		}
		i++;
	}
	return (state);
}
