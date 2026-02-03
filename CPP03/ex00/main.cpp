#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clap("Claudius");

	std::cout << "           Name: " << clap.getName() << std::endl
			  << "Hit points (10): " << clap.getHitPoints() << std::endl
			  << "    Energy (10): " << clap.getEnergyPoints() << std::endl
			  << "     Attack (0): " << clap.getAttackDamage() << std::endl;

	clap.attack("Brutus");
	clap.takeDamage(1);
	std::cout << "Hit points: " << clap.getHitPoints() << std::endl
			  << "    Energy: " << clap.getEnergyPoints() << std::endl;
	clap.beRepaired(1);
	std::cout << "Hit points: " << clap.getHitPoints() << std::endl
			  << "    Energy: " << clap.getEnergyPoints() << std::endl;
	clap.takeDamage(10);
	std::cout << "Hit points: " << clap.getHitPoints() << std::endl
			  << "    Energy: " << clap.getEnergyPoints() << std::endl;
	clap.attack("Brutus");
	clap.beRepaired(10);

	return (0);
}
