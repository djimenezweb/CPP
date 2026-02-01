#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clap("Claudius");

	clap.attack("Brutus");
	clap.takeDamage(1);
	clap.beRepaired(1);
	clap.attack("Brutus");

	clap.takeDamage(10);
	clap.attack("Brutus");
	clap.beRepaired(10);
	return (0);
}
