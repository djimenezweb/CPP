#include "PmergeMe.hpp"
#include <iomanip>
#include <sstream>
#include <limits>

std::string	underline(std::string str, size_t j)
{
	return (str.substr(0, j) + "\033[31;1m" + str[j] + "\033[0m" + str.substr(j + 1));
}

/* // Perform a basic integer validation by string length
bool	is_valid_integer(const std::string &str)
{
	if (str.find(' ') == std::string::npos && str.length() > 11)
	{
		std::cerr << "Error: Invalid number " << "\033[31;1m" << str << "\033[0m" << std::endl
				  << std::string(22, ' ') << "\033[31;1m^\033[0m" << std::endl;
		return (false);
	}
	return (true);
} */

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
		if (ss.fail() || number < 0 || number > std::numeric_limits<unsigned int>::max())
		{
			std::cerr << "Error: Invalid number " << "\033[31;1m" << std::fixed << std::setprecision(0) << number << "\033[0m" << std::endl
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
		if (!isdigit(str[j]) && !isspace(str[j]))
		{
			std::cerr << "Error: Invalid argument '" << underline(str, j) << "'" << std::endl
					  << std::string(25 + j, ' ') << "\033[31;1m^\033[0m" << std::endl;
			return (false);
		}
	}
	return (true);
}

/* bool validate_args(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++)
	{
		std::string	str = argv[i];
		if (!are_valid_chars(str))
			return (false);
		if (!are_valid_integers(str))
			return (false);
	}
	return (true);
} */

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cerr << "Correct usage: " << argv[0] << " <number1> <number2> ..." << std::endl;
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		std::string	str = argv[i];
		if (!are_valid_chars(str))
			return (1);
		if (!are_valid_integers(str))
			return (1);
	}

	std::cout << "Validation OK!" << std::endl << std::endl;

	try
	{
		PmergeMe pme(argc, argv);
		pme.initVector();
		pme.sort();
		// std::cout << pme.sort() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
