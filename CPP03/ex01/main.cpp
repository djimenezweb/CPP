#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	scav("Scavolini");

	std::cout << "            Name: " << scav.getName() << std::endl
			  << "Hit points (100): " << scav.getHitPoints() << std::endl
			  << "     Energy (50): " << scav.getEnergyPoints() << std::endl
			  << "     Attack (20): " << scav.getAttackDamage() << std::endl;

	scav.attack("Brutus");
	scav.guardGate();

	return (0);
}
