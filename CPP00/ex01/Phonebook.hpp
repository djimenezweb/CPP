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
		static int	i;
		static int	size;
		Contact		contacts[MAXSIZE];

	public:
		void		add();
		void		search();
		void		display_all();
		static void	increment_i();
		static void	increment_size();
};

#endif
