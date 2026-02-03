#include "FragTrap.hpp"

int main(void)
{
	FragTrap	frag("Frank");

	std::cout << "            Name: " << frag.getName() << std::endl
			  << "Hit points (100): " << frag.getHitPoints() << std::endl
			  << "    Energy (100): " << frag.getEnergyPoints() << std::endl
			  << "     Attack (30): " << frag.getAttackDamage() << std::endl;

	frag.attack("Brutus");
	frag.highFivesGuys();
	//frag.guardGate();

	return (0);
}
