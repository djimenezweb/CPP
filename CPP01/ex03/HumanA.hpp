#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		weapon;

	public:
		HumanA(std::string n, Weapon w)
		{
			this->name = n;
			this->weapon = w;
		}

		void	attack()
		{
			std::cout	<< this->name
						<< " attacks with their "
						<< this->weapon.getType()
						<< std::endl;
		}
};

#endif
