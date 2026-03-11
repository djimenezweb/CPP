#include "PmergeMe.hpp"

std::string	underline(std::string str, size_t j)
{
	return (str.substr(0, j) + "\033[31;1m" + str[j] + "\033[0m" + str.substr(j + 1));
}

// Cast arguments to double and check if they're beyond INT limits
bool	are_valid_integers(const std::string &str)
{
	double number;
	std::stringstream ss(str);

	while (!ss.eof())
	{
		ss >> std::ws;
		if (ss.eof())
			break ;
		ss >> number;
		if (ss.fail() || number < 0 || number > std::numeric_limits<int>::max())
		{
			std::cerr << ERROR "Invalid number " << "\033[31;1m" << std::fixed << std::setprecision(0) << number << "\033[0m" << std::endl
					  << std::string(22, ' ') << "\033[31;1m^\033[0m" << std::endl;
			return (false);
		}
	}
	return (true);
}

// Arguments should contain digits or spaces only
bool	are_valid_chars(const std::string &str)
{
	for (size_t j = 0; j < str.length(); j++)
	{
		if (!isdigit(str[j]) && !isspace(str[j]) && str[j] != '-')
		{
			std::cerr << ERROR "Invalid argument '" << underline(str, j) << "'" << std::endl
					  << std::string(25 + j, ' ') << "\033[31;1m^\033[0m" << std::endl;
			return (false);
		}
	}
	return (true);
}

// Return `true` if argument is made up of whitespace only
bool	is_ws_only(const std::string &str)
{
	size_t i = 0;
	while (i < str.length() && isspace(str[i]))
		i++;
	if (i == str.length())
	{
		std::cerr << ERROR "Invalid empty argument" << std::endl;
		return (true);
	}
	return (false);
}

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cerr << ERROR "Correct usage: " << argv[0] << " <number1> <number2> ..." << std::endl;
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		std::string	str = argv[i];
		if (is_ws_only(str))
			return (1);
		if (!are_valid_chars(str))
			return (1);
		if (!are_valid_integers(str))
			return (1);
	}

	try
	{
		PmergeMe pme(argc, argv);
		pme.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}
