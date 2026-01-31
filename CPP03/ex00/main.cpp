#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	albricius("Albricius");

	albricius.attack("Brutus");
	albricius.takeDamage(1);
	albricius.beRepaired(1);
	albricius.attack("Brutus");

	albricius.takeDamage(10);
	albricius.attack("Brutus");
	albricius.beRepaired(10);
	return (0);
}
