#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	frag("Frank");

	std::cout << "     Attack (30): " << frag.getAttackDamage() << std::endl
			  << "    Energy (100): " << frag.getEnergyPoints() << std::endl
			  << "Hit points (100): " << frag.getHitPoints() << std::endl;

	frag.highFivesGuys();
	return (0);
}
