#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	albricius("Albricius");

	albricius.attack("Brutus");
	albricius.takeDamage(1);
	albricius.beRepaired(1);
	albricius.attack("Brutus");
	albricius.guardGate();

	albricius.takeDamage(10);
	albricius.attack("Brutus");
	albricius.beRepaired(10);
	return (0);
}
