#include "converter.hpp"

int	calc_precision(const std::string &str)
{
	size_t	end;
	size_t	precision;
	size_t	index;

	end = str.rfind('f');
	if (end == std::string::npos)
		end = str.length();

	precision = 1;
	index = str.find('.');
	if (index != std::string::npos)
		precision = end - 1 - index;

	return ((int)precision);
}

void	print_double(const double d, const std::string &str)
{
	if (is_valid_double(str))
	{
		int	precision = calc_precision(str);
		std::cout << std::fixed << std::setprecision(precision)
				  << "double: " << d << std::endl;
	}
	else
		std::cout << "double: (Overflow)" << std::endl;
}

void	print_float(const float f, const std::string &str)
{
	if (is_valid_float(str))
	{
		int	precision = calc_precision(str);
		std::cout << std::fixed << std::setprecision(precision)
				  << " float: " << f << "f" << std::endl;
	}
	else
		std::cout << " float: (Overflow)" << std::endl;
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

void	print_string(const std::string &str)
{
	if (is_quoted_char(str))
		convert_char(&str[1]);
	else if (is_pseudo_lit(str))
	{
		std::cout << "  char: (Impossible)" << std::endl
				  << "   int: (Impossible)" << std::endl;
		print_float(static_cast<float>(std::atof(str.c_str())), str);
		print_double(static_cast<double>(std::atof(str.c_str())), str);
	}
	else
		std::cout << "Invalid string literal" << std::endl;
}
