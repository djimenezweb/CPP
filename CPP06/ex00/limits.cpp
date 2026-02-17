#include "converter.hpp"

/*
	CHAR_MIN =	-128
	CHAR_MAX =	 127

	INT_MIN =	-2147483648
	INT_MAX =	 2147483647

	FLT_MIN =	 0.0
	FLT_MAX =	 340282346638528859811704183484516925440.0

	DBL_MIN =	 0.0
	DBL_MAX =	 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
*/

size_t	integer_part_length(const std::string &str)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (str.find_first_of("+-") != std::string::npos)
		start++;
	end = str.find('.');
	if (end == std::string::npos)
		end = str.length();

	return (end - start);
}

bool	is_quoted_char(const std::string &str)
{
	if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
		return (true);
	return (false);
}

bool	is_pseudo_lit(const std::string &str)
{
	std::string pseudo_lit[] = { "nan", "-inf", "+inf", "nanf", "-inff", "+inff" };

	for (size_t i = 0; i < 6; i++)
	{
		if (str == pseudo_lit[i])
			return (true);
	}
	return (false);
}

bool	is_valid_double(const std::string &str)
{
	if (integer_part_length(str) <= 309)
	{
		if (is_pseudo_lit(str))
			return (true);

		long double value = static_cast<long double>(std::strtold(str.c_str(), NULL));

		if (value >= -DBL_MAX && value <= DBL_MAX)
			return (true);
	}
	return (false);
}

bool	is_valid_float(const std::string &str)
{
	if (integer_part_length(str) <= 39)
	{
		if (is_pseudo_lit(str))
		return (true);

		double value = static_cast<double>(std::atof(str.c_str()));

		if (value >= -FLT_MAX && value <= FLT_MAX)
			return (true);
	}
	return (false);
}

bool	is_valid_int(const std::string &str)
{
	if (integer_part_length(str) <= 10)
	{
		double value = static_cast<double>(std::atof(str.c_str()));

		if (value >= INT_MIN && value <= INT_MAX)
			return (true);
	}
	return (false);
}

bool	is_valid_char(const std::string &str)
{
	if (integer_part_length(str) > 3)
		return (false);

	int value = static_cast<int>(std::atoi(str.c_str()));

	if (value >= CHAR_MIN && value <= CHAR_MAX)
		return (true);
	return (false);
}
