#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	albricius("Albricius");
	//ClapTrap	brutus("Brutus");

	albricius.attack("Brutus");
	albricius.takeDamage(10);
	albricius.attack("Brutus");
	albricius.beRepaired(4);
	return (0);
}
