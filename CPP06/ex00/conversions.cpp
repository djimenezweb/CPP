#include "converter.hpp"

void	out_of_range(const std::string &str, std::string type)
{
	std::cout << str << " is outside the range of representable values of type '" << type << "'" << std::endl;
}

void	convert_double(const std::string &str)
{
	if (!is_valid_double(str))
		return (out_of_range(str, "double"));

	double	value = static_cast<double>(std::atof(str.c_str()));

	print_char(static_cast<char>(value), str);
	print_int(static_cast<int>(value), str);
	print_float(static_cast<float>(value), str);
	print_double(value, str);
}

void	convert_float(const std::string &str)
{
	if (!is_valid_float(str))
		return (out_of_range(str, "float"));

	float	value = static_cast<float>(std::atof(str.c_str()));

	print_char(static_cast<char>(value), str);
	print_int(static_cast<int>(value), str);
	print_float(value, str);
	print_double(static_cast<double>(value), str);
}

void convert_int(const std::string &str)
{
	if (!is_valid_int(str))
		return (out_of_range(str, "int"));

	int	value = static_cast<int>(std::atoi(str.c_str()));

	print_char(static_cast<char>(value), str);
	print_int(value, str);
	print_float(static_cast<float>(value), str);
	print_double(static_cast<double>(value), str);
}

void convert_char(const std::string &str)
{
	char	value = static_cast<char>(str[0]);

	print_char(value, str);
	print_int(static_cast<int>(value), str);
	print_float(static_cast<float>(value), str);
	print_double(static_cast<double>(value), str);
}
