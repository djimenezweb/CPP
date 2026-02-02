#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	frag("Frank");

	std::cout << "Hit points (100): " << frag.getHitPoints() << std::endl
			  << "     Energy (50): " << frag.getEnergyPoints() << std::endl
			  << "     Attack (30): " << frag.getAttackDamage() << std::endl;

	frag.highFivesGuys();
	return (0);
}
