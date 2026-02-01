#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	scav("Scavolini");

	std::cout << "     Attack (20): " << scav.getAttackDamage() << std::endl
			  << "     Energy (50): " << scav.getEnergyPoints() << std::endl
			  << "Hit points (100): " << scav.getHitPoints() << std::endl;

	//albricius.guardGate();
	//albricius.attack("Brutus");
	//albricius.takeDamage(1);
	//albricius.beRepaired(1);
	//albricius.attack("Brutus");
	//albricius.guardGate();
//
	//albricius.takeDamage(10);
	//albricius.attack("Brutus");
	//albricius.beRepaired(10);
	return (0);
}
