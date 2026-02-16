#include "converter.hpp"

int	calc_precision(const std::string &str)
{
	size_t	precision = 1;

	size_t	end = str.rfind('f');
	if (end == std::string::npos)
		end = str.length();

	size_t	index = str.find('.');
	if (index != std::string::npos)
	{
		precision = end - 1 - index;
		// std::cout << "Number of decimals: " << precision << std::endl;
	}
	// std::cout << "Returning: " << precision << std::endl;
	return ((int)precision);
}

void	print_double(const double d, const std::string &str)
{
	if (!is_valid_double(str))
	{
		std::cout << "double: (Overflow)" << std::endl;
		return;
	}
	int	precision = calc_precision(str);
	std::cout << std::fixed << std::setprecision(precision)
			  << "double: " << d << std::endl;
}

void	print_float(const float f, const std::string &str)
{
	if (!is_valid_float(str))
	{
		std::cout << " float: (Overflow)" << std::endl;
		return;
	}
	int	precision = calc_precision(str);
	std::cout << std::fixed << std::setprecision(precision)
			  << " float: " << f << "f" << std::endl;
}

void	print_int(const int i, const std::string &str)
{
	if (is_valid_int(str))
		std::cout << "   int: " << i << std::endl;
	else
		std::cout << "   int: (Overflow)" << std::endl;
}

void	print_char(const char c, const std::string &str)
{
	if (is_valid_char(str))
	{
		if (isprint(c))
			std::cout << "  char: '" << c << "'" << std::endl;
		else
			std::cout << "  char: (Non displayable)" << std::endl;
	}
	else
		std::cout << "  char: (Overflow)" << std::endl;
}
