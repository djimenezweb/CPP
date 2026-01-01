#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private :
		std::string	name;
	
	public :
		Zombie();
		//Zombie(std::string set_name);
		~Zombie();
		void set_name(std::string set_name);
		void announce(void);
};

#endif
