#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>
# include "ClapTrap.hpp"

# define SCAV_HITPTS 100
# define SCAV_ENERGY 50
# define SCAV_ATTACK 20

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
