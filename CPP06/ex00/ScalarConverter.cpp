#include "ScalarConverter.hpp"
#include "converter.hpp"

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

static const std::string pseudo_lit[] = { "nan", "-inf", "+inf", "nanf", "-inff", "+inff" };

void	print_string(const std::string &str)
{
	if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		convert_char(&str[1]);
		return ;
	}
	for (size_t i = 0; i < 6; i++)
	{
		if (str == pseudo_lit[i])
		{
			std::cout << "  char: (Impossible)" << std::endl
					  << "   int: (Impossible)" << std::endl
					  << " float: " << static_cast<float>(std::atof(str.c_str())) << "f" << std::endl
					  << "double: " << static_cast<double>(std::atof(str.c_str())) << std::endl;
			return ;
		}
	}
	std::cout << "Invalid string literal" << std::endl;
}

void (*actions[])(const std::string&) = { convert_char, print_string, convert_int, convert_double, convert_float };

// Convert
void ScalarConverter::convert(const std::string &str)
{
	// std::cout << std::endl << "CONVERT: <" << str << ">" << std::endl;
	State state = detect(str);
	if (state < S_INVALID)
		actions[state](str);
	else
		std::cerr << "Invalid argument" << std::endl;
}
