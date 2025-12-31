#include "Phonebook.hpp"

std::string	trunc_str(std::string str, int max_size);

int Phonebook::i = 0;
int Phonebook::size = 0;

void	Phonebook::add()
{
	contacts[i].set_first_name();
	contacts[i].set_last_name();
	contacts[i].set_nick_name();
	contacts[i].set_phone_number();
	contacts[i].set_darkest_secret();
	std::cout << "Contact " << contacts[i].get_first_name()
			<< " added to phonebook (" << i + 1 << ")" << std::endl;
	increment_i();
	increment_size();
}

void	Phonebook::increment_i()
{
	Phonebook::i = (Phonebook::i + 1) % MAXSIZE;
}

void	Phonebook::increment_size()
{
	if (Phonebook::size < MAXSIZE)
		Phonebook::size++;
}

void	Phonebook::display_all()
{
	if (Phonebook::size == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	std::cout	<< "|" << std::setw(COLWIDTH) << "#"
				<< "|" << std::setw(COLWIDTH) << "FIRST NAME"
				<< "|" << std::setw(COLWIDTH) << "LAST NAME"
				<< "|" << std::setw(COLWIDTH) << "NICKNAME"
				<< "|" << std::endl;
	for (int j = 0; j < Phonebook::size; j++)
	{
		std::cout	<< "|" << std::setw(COLWIDTH) << j + 1
					<< "|" << std::setw(COLWIDTH) << trunc_str(contacts[j].get_first_name(), COLWIDTH)
					<< "|" << std::setw(COLWIDTH) << trunc_str(contacts[j].get_last_name(), COLWIDTH)
					<< "|" << std::setw(COLWIDTH) << trunc_str(contacts[j].get_nick_name(), COLWIDTH)
					<< "|" << std::endl;
	}
}

void	Phonebook::search()
{
	std::string	input;

	display_all();

	while (!std::cin.eof())
	{
		int	index;

		std::cout << "Select contact (1-" << size << ") : ";
		std::getline(std::cin, input);
		index = std::atoi(input.data());
		if (index >= 1 && index <= size)
		{
			contacts[index - 1].display_contact();
			break ;
		}
		else
			input.clear();
	}
}
