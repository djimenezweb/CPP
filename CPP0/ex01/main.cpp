#include <iostream>
#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	phonebook;
	std::string	prompt;

	while (!std::cin.eof())
	{
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		std::getline(std::cin, prompt);
		if (prompt == "EXIT")
			return (0);
		else if (prompt == "ADD")
			phonebook.add();
		else if (prompt == "SEARCH")
			phonebook.search();
		prompt.clear();
	}
	
	return (0);
}
