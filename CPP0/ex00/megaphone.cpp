#include <iostream>

#define DEFAULT "* LOUD AND UNBEARABLE NOISE *"

int	main(int argc, char *argv[])
{
	std::string	str;

	if (argc == 1)
	{
		std::cout << DEFAULT << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
			str[j] = toupper(str[j]);
		std::cout << str;
	}
	std::cout << std::endl;

	return (0);
}
