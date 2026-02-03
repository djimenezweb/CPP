#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "CONSTRUCTORS" << std::endl;
	DiamondTrap	diamond("Dianne");
	std::cout << std::endl;

	std::cout << "            Name: " << diamond.getName() << std::endl
			  << "Hit points (100): " << diamond.getHitPoints() << std::endl
			  << "     Energy (50): " << diamond.getEnergyPoints() << std::endl
			  << "     Attack (30): " << diamond.getAttackDamage() << std::endl;

	std::cout << std::endl << "WHO AM I" << std::endl;
	diamond.whoAmI();
	std::cout << std::endl;

	diamond.attack("Brutus");
	diamond.guardGate();
	diamond.highFivesGuys();

	std::cout << std::endl << "DESTRUCTORS" << std::endl;

	return (0);
}
