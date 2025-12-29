#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

# define MAXSIZE 8
# define COLWIDTH 10

class	Phonebook
{
	private:
		int		i;
		int		size;
		Contact	contacts[MAXSIZE];

	public:
		void	add();
		void	search();
		void	display_all();
		Phonebook();
};

#endif
