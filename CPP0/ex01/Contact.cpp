#include "Contact.hpp"

// getters

std::string	Contact::get_first_name()
{
	return (this->first_name);
}

std::string	Contact::get_last_name()
{
	return (this->last_name);
}

std::string	Contact::get_nick_name()
{
	return (this->nick_name);
}

std::string	Contact::get_phone_number()
{
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return (this->darkest_secret);
}

// setters

void	Contact::set_first_name(std::string str)
{
	this->first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->last_name = str;
}

void	Contact::set_nick_name(std::string str)
{
	this->nick_name = str;
}

void	Contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}

// Auxiliary functions

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

std::string	Contact::get_input(std::string label)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << label;
		std::getline(std::cin, input);
		if (label == PHON_LBL && !is_valid_phone(input))
			input.clear();
	}
	return (input);
}

void	Contact::display_contact()
{
	std::cout << FRST_LBL << this->get_first_name() << std::endl
		<< LAST_LBL << this->get_last_name() << std::endl
		<< NICK_LBL << this->get_nick_name() << std::endl
		<< PHON_LBL << this->get_phone_number() << std::endl
		<< DARK_LBL << this->get_darkest_secret() << std::endl;
}
