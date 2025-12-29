#include <iostream>
#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	input;

	while (!std::cin.eof())
	{
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);
		if (input == "EXIT")
			return (0);
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		input.clear();
	}
	
	return (0);
}
