#include "Phonebook.hpp"

Phonebook::Phonebook() : i(0), size(0) {}

void	Phonebook::add()
{
	contacts[i].set_first_name(contacts[i].get_input(FRST_LBL));
	contacts[i].set_last_name(contacts[i].get_input(LAST_LBL));
	contacts[i].set_nick_name(contacts[i].get_input(NICK_LBL));
	contacts[i].set_phone_number(contacts[i].get_input(PHON_LBL));
	contacts[i].set_darkest_secret(contacts[i].get_input(DARK_LBL));
	std::cout << "Contact " << contacts[i].get_first_name()
			<< " added to phonebook (" << i + 1 << ")" << std::endl;
	i = (i + 1) % MAXSIZE;
	if (size < MAXSIZE)
		size++;
}

std::string	trunc_str(std::string str)
{
	if (str.length() > COLWIDTH)
		return (str.substr(0, COLWIDTH - 1).append("."));
	else
		return (str);
}

void	Phonebook::search()
{
	std::string	prompt;

	if (size == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	std::cout	<< "|" << std::setw(COLWIDTH) << "#"
				<< "|" << std::setw(COLWIDTH) << "FIRST NAME"
				<< "|" << std::setw(COLWIDTH) << "LAST NAME"
				<< "|" << std::setw(COLWIDTH) << "NICKNAME"
				<< "|" << std::endl;
	for (int j = 0; j < size; j++)
	{
		std::cout	<< "|" << std::setw(COLWIDTH) << j + 1
					<< "|" << std::setw(COLWIDTH) << trunc_str(contacts[j].get_first_name())
					<< "|" << std::setw(COLWIDTH) << trunc_str(contacts[j].get_last_name())
					<< "|" << std::setw(COLWIDTH) << trunc_str(contacts[j].get_nick_name())
					<< "|" << std::endl;
	}

	while (!std::cin.eof())
	{
		int	index;

		std::cout << "Select contact (1-" << size << ") : ";
		std::getline(std::cin, prompt);
		index = std::atoi(prompt.data());
		if (index >= 1 && index <= size)
		{
			contacts[index - 1].display_contact();
			break ;
		}
		else
			prompt.clear();
	}
}
