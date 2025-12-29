#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

# define FRST_LBL " First name     : "
# define LAST_LBL " Last name      : "
# define NICK_LBL " Nickname       : "
# define PHON_LBL " Phone          : "
# define DARK_LBL " Darkest secret : "

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;

	public :
		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_nick_name(std::string str);
		void		set_phone_number(std::string str);
		void		set_darkest_secret(std::string str);
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nick_name();
		std::string	get_phone_number();
		std::string	get_darkest_secret();
		std::string	get_input(std::string label);
		void		display_contact();
};

#endif
