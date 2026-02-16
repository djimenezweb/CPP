#include "ScalarConverter.hpp"
#include "state_machine.hpp"
#include "utils.hpp"

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

void	print_double(const std::string &str)
{
	if (!is_valid_double(str))
	{
		std::cerr << str << " is outside the range of representable values of type 'double'" << std::endl;
		return;
	}

	double	value = static_cast<double>(std::atof(str.c_str()));
	float	f = static_cast<float>(std::atof(str.c_str()));

	std::cout << std::fixed << std::setprecision(1);
	// ft_printint(static_cast<int>(value));
	if (is_char_print(str))
		std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "  char: (Non displayable)" << std::endl;
	if (value <= INT_MAX && value >= INT_MIN)
		std::cout << "   int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "   int: impossible" << std::endl;
	if (static_cast<double>(f) == value)
		std::cout << " float: " << static_cast<float>(value) << "f" << std::endl;
	else
		std::cout << " float: (imprecise)" << std::endl;
	std::cout << "double: " << value << std::endl;
}

void	print_float(const std::string &str)
{
	if (!is_valid_float(str))
	{
		std::cerr << str << " is outside the range of representable values of type 'float'" << std::endl;
		return;
	}
	// char c = '2';
	float	value = static_cast<float>(std::atof(str.c_str()));
	//double	d = static_cast<float>(std::atof(str.c_str()));
	std::cout << std::fixed << std::setprecision(5);
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
	std::cout << std::fixed << std::setprecision(1);

	if (is_char_print(str))
		std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "  char: (Non displayable)" << std::endl;
	std::cout << "   int: " << value << std::endl
			  << " float: " << static_cast<float>(value) << "f" << std::endl
			  << "double: " << static_cast<double>(value) << std::endl;
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
	if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
	{
		print_char(&str[1]);
		return ;
	}
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
	std::cout << std::endl << "CONVERT: <" << str << ">" << std::endl;
	State state = detect(str);
	if (state < S_INVALID)
		actions[state](str);
	else
		std::cerr << "Invalid argument" << std::endl;
}
