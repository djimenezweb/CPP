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

bool is_valid_double(const std::string &str)
{
	long double value = static_cast<long double>(std::strtold(str.c_str(), NULL));

	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
		return (false);
	return (true);
}

bool is_valid_float(const std::string &str)
{
	double value = static_cast<double>(std::atof(str.c_str()));

	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		return (false);
	return (true);
}

bool is_valid_int(const std::string &str)
{
	double value = static_cast<double>(std::atof(str.c_str()));

	if (value < -std::numeric_limits<int>::max() || value > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

bool is_valid_char(const std::string &str)
{
	int value = static_cast<int>(std::atoi(str.c_str()));

	if (value < -CHAR_MAX || value > CHAR_MAX)
		return (false);
	return (true);
}

bool is_char_print(const std::string &str)
{
	long double value = static_cast<long double>(std::atof(str.c_str()));

	if (value > 32 && value < 127)
		return (true);
	return (false);
}

void	print_double(const std::string &str)
{
	if (!is_valid_double(str))
	{
		std::cerr << str << " is outside the range of representable values of type 'double'" << std::endl;
		return;
	}

	double	value = static_cast<double>(std::atof(str.c_str()));

	if (is_char_print(str))
		std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "  char: (Non displayable)" << std::endl;
	std::cout << "   int: " << static_cast<int>(value) << std::endl
			  << " float: " << static_cast<float>(value) << "f" << std::endl
			  << "double: " << value << std::endl;
}

void	print_float(const std::string &str)
{
	if (!is_valid_float(str))
	{
		std::cerr << str << " is outside the range of representable values of type 'float'" << std::endl;
		return;
	}

	float	value = static_cast<float>(std::atof(str.c_str()));

	if (is_char_print(str))
		std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "  char: (Non displayable)" << std::endl;
	std::cout << "   int: " << static_cast<int>(value) << std::endl
			  << " float: " << value << "f" << std::endl
			  << "double: " << static_cast<double>(value) << std::endl;
}

void print_int(const std::string &str)
{
	if (!is_valid_int(str))
	{
		std::cerr << str << " is outside the range of representable values of type 'int'" << std::endl;
		return;
	}

	int	value = static_cast<int>(std::atoi(str.c_str()));

	if (is_char_print(str))
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
	std::cout << "Invalid string literal" << std::endl;
}

void (*actions[])(const std::string&) = { print_char, print_pseudo_lit, print_int, print_double, print_float };

// Convert
void ScalarConverter::convert(const std::string &str)
{
	State state = detect(str);
	if (state < S_INVALID)
		actions[state](str);
	else
		std::cerr << "Invalid argument" << std::endl;
}
