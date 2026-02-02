#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	ClapTrap	clap("Claudius");
	ScavTrap	scav("Scavolini");
	FragTrap	frag("Frank");
	DiamondTrap	dianne("Dianne");


	std::cout << "Hit points (100): " << dianne.getHitPoints() << std::endl
			  << "     Energy (50): " << dianne.getEnergyPoints() << std::endl
			  << "     Attack (30): " << dianne.getAttackDamage() << std::endl;

	return (0);
}
