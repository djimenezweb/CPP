#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

# define CLAP_HITPTS 10
# define CLAP_ENERGY 10
# define CLAP_ATTACK 0

class ClapTrap
{
	private:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	
	public:
		ClapTrap();
		ClapTrap(std::string set_name);
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);

		std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
		void			setName(std::string set_name);
		void			setHitPoints(unsigned int value);
		void			setEnergyPoints(unsigned int value);
		void			setAttackDamage(unsigned int value);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
