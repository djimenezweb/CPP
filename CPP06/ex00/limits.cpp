#include "ScalarConverter.hpp"

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
