#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string set_name);
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);

		void	attack(const std::string &target);
		void	guardGate();
};

#endif
