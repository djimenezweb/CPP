#include "converter.hpp"

/*
	CHAR	-128			127

	INT		-2147483648		2147483647

	FLOAT	0.0				340282346638528859811704183484516925440.0

	DOUBLE	0.0				179769313486231570814527423731704356798070567525844
							996598917476803157260780028538760589558632766878171
							540458953514382464234321326889464182768467546703537
							516986049910576551282076245490090389328944075868508
							455133942304583236903222948165808559332123348274797
							826204144723168738177180919299881250404026184124858
							368.0
*/

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
	if (is_pseudo_lit(str))
		return (true);

	long double value = static_cast<long double>(std::strtold(str.c_str(), NULL));

	if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
		return (false);
	return (true);
}

bool	is_valid_float(const std::string &str)
{
	if (is_pseudo_lit(str))
		return (true);

	double value = static_cast<double>(std::atof(str.c_str()));

	if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		return (false);
	return (true);
}

bool	is_valid_int(const std::string &str)
{
	double value = static_cast<double>(std::atof(str.c_str()));

	if (value >= INT_MIN && value <= INT_MAX)
		return (true);
	return (false);
}

bool	is_valid_char(const std::string &str)
{
	int value = static_cast<int>(std::atoi(str.c_str()));

	if (value >= CHAR_MIN && value <= CHAR_MAX)
		return (true);
	return (false);
}
