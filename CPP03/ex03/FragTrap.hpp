#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

# define FRAG_HITPTS 100
# define FRAG_ENERGY 100
# define FRAG_ATTACK 30

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string set_name);
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);

		void	attack(const std::string &target);
		void	highFivesGuys();
};

#endif
