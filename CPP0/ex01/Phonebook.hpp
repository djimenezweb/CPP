#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

# define MAXSIZE 8
# define COLWIDTH 10
# define FIRS_LBL " First name     : "
# define LAST_LBL " Last name      : "
# define NICK_LBL " Nickname       : "
# define PHON_LBL " Phone          : "
# define DARK_LBL " Darkest secret : "

class	Phonebook
{
	private:
		int			i;
		int			size;
		Contact		contacts[MAXSIZE];
		std::string	set_string(std::string label);
		std::string	set_number(std::string label);

	public:
		Phonebook(void);
		void		add(void);
		void		search(void);
};

#endif
