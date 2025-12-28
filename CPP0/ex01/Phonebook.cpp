#include "Phonebook.hpp"

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

void	trunc_str(std::string str)
{
	std::cout << std::setw(COLWIDTH);
	if (str.length() > COLWIDTH)
		std::cout << str.substr(0, COLWIDTH - 1).append(".");
	else
		std::cout << str;
	std::cout << "|";
}

void	display_contact(Contact c)
{
	std::cout << FIRS_LBL << c.first_name << std::endl
		<< LAST_LBL << c.last_name << std::endl
		<< NICK_LBL << c.nick_name << std::endl
		<< PHON_LBL << c.phone_number << std::endl
		<< DARK_LBL << c.darkest_secret << std::endl;
}

Phonebook::Phonebook(void) : i(0), size(0) {}

std::string	Phonebook::set_string(std::string label)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << label;
		std::getline(std::cin, input);
	}
	return (input);
}

std::string	Phonebook::set_number(std::string label)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << label;
		std::getline(std::cin, input);
		if (!is_valid_phone(input))
			input.clear();
	}
	return (input);
}

void	Phonebook::add(void)
{
	contacts[i].first_name = set_string(FIRS_LBL);
	contacts[i].last_name = set_string(LAST_LBL);
	contacts[i].nick_name = set_string(NICK_LBL);
	contacts[i].phone_number = set_number(PHON_LBL);
	contacts[i].darkest_secret = set_string(DARK_LBL);
	std::cout << "Contact " << contacts[i].first_name
			<< " added to phonebook (" << i + 1 << ")" << std::endl;
	i = (i + 1) % MAXSIZE;
	if (size < MAXSIZE)
		size++;
}

void	Phonebook::search()
{
	std::string	prompt;

	if (size == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	std::cout << "|";
	std::cout << std::setw(COLWIDTH) << "#";
	std::cout << "|";
	std::cout << std::setw(COLWIDTH) << "FIRST NAME";
	std::cout << "|";
	std::cout << std::setw(COLWIDTH) << "LAST NAME";
	std::cout << "|";
	std::cout << std::setw(COLWIDTH) << "NICKNAME";
	std::cout << "|" << std::endl;
	for (int j = 0; j < size; j++)
	{
		std::cout << "|";
		std::cout << std::setw(COLWIDTH);
		std::cout << j + 1 << "|";
		trunc_str(contacts[j].first_name);
		trunc_str(contacts[j].last_name);
		trunc_str(contacts[j].nick_name);
		std::cout << std::endl;
	}

	while (!std::cin.eof())
	{
		int	index;
		std::cout << "Select contact (1-" << size << ") : ";
		std::getline(std::cin, prompt);
		index = std::atoi(prompt.data());
		if (index >= 1 && index <= size)
		{
			display_contact(contacts[index - 1]);
			break ;
		}
		else
			prompt.clear();
	}
}
