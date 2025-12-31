# include "utils.hpp"

std::string	trunc_str(std::string str, int max_size)
{
	if (str.length() > (size_t)max_size)
		return (str.substr(0, max_size - 1).append("."));
	else
		return (str);
}

std::string trim(std::string& str)
{
	std::size_t	start;
	std::size_t	end;

	start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos)
		return "";
	end = str.find_last_not_of(" \t\n\r\f\v");

	return (str.substr(start, end - start + 1));
}

bool	is_valid_phone(std::string str)
{
	size_t	start = 0;
	if (str[start] == '+')
		start++;
	for (size_t i = start; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}
