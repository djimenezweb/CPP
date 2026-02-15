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

std::string pseudo_lit[] = { "nan", "-inf", "+inf", "nanf", "-inff", "+inff" };

void	cast_double(const std::string &str)
{
	double	value = static_cast<double>(std::atof(str.c_str()));

	std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl
			  << "   int: " << static_cast<int>(value) << std::endl
			  << " float: " << static_cast<float>(value) << "f" << std::endl
			  << "double: " << value << std::endl;
}

void	cast_float(const std::string &str)
{
	float	value = static_cast<float>(std::atof(str.c_str()));

	std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl
			  << "   int: " << static_cast<int>(value) << std::endl
			  << " float: " << value << "f" << std::endl
			  << "double: " << static_cast<double>(value) << std::endl;
}

void cast_int(const std::string &str)
{
	int	value = static_cast<int>(std::atoi(str.c_str()));

	if (isprint(value))
		std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "  char: (Non displayable)" << std::endl;
	//std::cout << "  char: '" << static_cast<char>(value) << "'" << std::endl
	std::cout << "   int: " << value << std::endl
			  << " float: " << static_cast<float>(value) << ".0f" << std::endl
			  << "double: " << static_cast<double>(value) << ".0" << std::endl;
}

void cast_char(const std::string &str)
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

void	cast_pseudo_lit(const std::string &str)
{
	for (size_t i = 0; i < 6; i++)
	{
		if (pseudo_lit[i] == str)
		{
			std::cout << "  char: impossible" << std::endl
					  << "   int: impossible" << std::endl;
			if (i <= 2)
			{
				// std::cout << " float: " << str << "f" << std::endl
				// 		  << "double: " << str << std::endl;
				std::cout << " float: " << static_cast<float>(std::atof(str.c_str())) << "f" << std::endl
						  << "double: " << static_cast<double>(std::atof(str.c_str())) << std::endl;
			}
			else
			{
				// std::cout << " float: " << str << std::endl
				// 		  << "double: " << pseudo_lit[i - 3] << std::endl;
				std::cout << " float: " << static_cast<float>(std::atof(str.c_str())) << "f" << std::endl
						  << "double: " << static_cast<double>(std::atof(str.c_str())) << std::endl;
			}
			return ;
		}
	}
	std::cout << "Invalid argument" << std::endl;
}

std::string type_str[__TYPE_SIZE] = { "char", "string", "int", "double", "float", "invalid" };

// Convert
void ScalarConverter::convert(const std::string &str)
{
	Type type = detect(str);
	std::cout << "Argument <" << str << "> is of type " << type_str[type] << std::endl;
	switch (type)
	{
	case T_CHAR:
		cast_char(str);
		break;
	case T_INT:
		cast_int(str);
		break;
	case T_FLOAT:
		cast_float(str);
		break;
	case T_DOUBLE:
		cast_double(str);
		break;
	default:
		cast_pseudo_lit(str);
		break;
	}
}
