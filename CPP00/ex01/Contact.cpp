#include "Contact.hpp"

std::string trim(std::string& str);
bool is_valid_phone(std::string str);

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

void	Contact::set_first_name()
{
	this->first_name = get_input(FRST_LBL);
}

void	Contact::set_last_name()
{
	this->last_name = get_input(LAST_LBL);
}

void	Contact::set_nick_name()
{
	this->nick_name = get_input(NICK_LBL);
}

void	Contact::set_phone_number()
{
	this->phone_number = get_input(PHON_LBL);
}

void	Contact::set_darkest_secret()
{
	this->darkest_secret = get_input(DARK_LBL);
}

// Auxiliary functions

std::string	Contact::get_input(std::string label)
{
	std::string	input;

	while (trim(input).empty())
	{
		std::cout << label;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ("");
		if (label == PHON_LBL && !is_valid_phone(input))
			input.clear();
	}
	return (trim(input));
}

void	Contact::display_contact()
{
	std::cout << FRST_LBL << this->get_first_name() << std::endl
		<< LAST_LBL << this->get_last_name() << std::endl
		<< NICK_LBL << this->get_nick_name() << std::endl
		<< PHON_LBL << this->get_phone_number() << std::endl
		<< DARK_LBL << this->get_darkest_secret() << std::endl;
}
