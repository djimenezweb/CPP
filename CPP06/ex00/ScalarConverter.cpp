#include "ScalarConverter.hpp"
#include "state_machine.hpp"

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

bool is_valid_range(const std::string &str, long min, long max)
{
	long lvalue = static_cast<long>(std::atol(str.c_str()));
	if (lvalue < min || lvalue > max)
		return (false);
	return (true);
}

void	print_double(const std::string &str)
{
	// long lvalue = static_cast<long>(std::atol(str.c_str()));
	// if (lvalue < (long)DBL_MIN || lvalue > (long)DBL_MAX)
	if (!is_valid_range(str, (long)DBL_MIN, (long)DBL_MAX))
	{
		std::cout << str << " is out of range of float values" << std::endl;
		return;
	}

	double	value = static_cast<double>(std::atof(str.c_str()));

	if ((value >= CHAR_MIN && value <= CHAR_MAX) && isprint(static_cast<int>(value)))
		std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "  char: (Non displayable)" << std::endl;
	std::cout << "   int: " << static_cast<int>(value) << std::endl
			  << " float: " << static_cast<float>(value) << "f" << std::endl
			  << "double: " << value << std::endl;
}

void	print_float(const std::string &str)
{
	// long lvalue = static_cast<long>(std::atol(str.c_str()));
	// if (lvalue < (long)FLT_MIN || lvalue > (long)FLT_MAX)
	if (!is_valid_range(str, (long)FLT_MIN, (long)FLT_MAX))
	{
		std::cout << str << " is out of range of float values" << std::endl;
		return;
	}

	float	value = static_cast<float>(std::atof(str.c_str()));

	if ((value >= CHAR_MIN && value <= CHAR_MAX) && isprint(static_cast<int>(value)))
		std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "  char: (Non displayable)" << std::endl;
	std::cout << "   int: " << static_cast<int>(value) << std::endl
			  << " float: " << value << "f" << std::endl
			  << "double: " << static_cast<double>(value) << std::endl;
}

void print_int(const std::string &str)
{
	// long lvalue = static_cast<long>(std::atol(str.c_str()));
	// if (lvalue < INT_MIN || lvalue > INT_MAX)
	if (!is_valid_range(str, (long)INT_MIN, (long)INT_MAX))
	{
		std::cout << str << " is out of range of int values" << std::endl;
		return;
	}

	int	value = static_cast<int>(std::atoi(str.c_str()));

	if (value >= CHAR_MIN && value <= CHAR_MAX)
		std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "  char: (Non displayable)" << std::endl;
	std::cout << "   int: " << value << std::endl
			  << " float: " << static_cast<float>(value) << ".0f" << std::endl
			  << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void print_char(const std::string &str)
{
	char	value = static_cast<char>(str[0]);

	if (isprint(str[0]))
		std::cout << "  char: '" << value << "'" << std::endl;
	else
		std::cout << "  char: (Non displayable)" << std::endl;
	std::cout << "   int: " << static_cast<int>(value) << std::endl
			  << " float: " << static_cast<float>(value) << ".0f" << std::endl
			  << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

static const std::string pseudo_lit[] = { "nan", "-inf", "+inf", "nanf", "-inff", "+inff" };

void	print_pseudo_lit(const std::string &str)
{
	for (size_t i = 0; i < 6; i++)
	{
		if (str == pseudo_lit[i])
		{
			std::cout << "  char: impossible" << std::endl
					  << "   int: impossible" << std::endl
					  << " float: " << static_cast<float>(std::atof(str.c_str())) << "f" << std::endl
					  << "double: " << static_cast<double>(std::atof(str.c_str())) << std::endl;
			return ;
		}
	}
	std::cout << "Invalid argument" << std::endl;
}

void (*actions[])(const std::string&) = { print_char, print_pseudo_lit, print_int, print_double, print_float };

// Convert
void ScalarConverter::convert(const std::string &str)
{
	State state = detect(str);
	actions[state](str);
}
