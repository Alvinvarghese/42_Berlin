#include "DiamondTrap.h"
/*
int main()
{
	DiamondTrap diamondTrap("Diamond");
	std::cout << std::endl;
	diamondTrap.attack("-->Target1<--");
	diamondTrap.takeDamage(20);
	diamondTrap.beRepaired(10);
	diamondTrap.guardGate();
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();
	diamondTrap.takeDamage(100); // Should destroy the DiamondTrap
	diamondTrap.attack("-->Target2<--"); // Should not attack since it's destroyed
	diamondTrap.whoAmI(); // Should not print anything since it's destroyed
	std::cout << std::endl;
	return 0;
}
*/

int main()
{
	DiamondTrap dt("Diamond");

	std::cout << std::endl;
	dt.get_hitPoints();
	dt.get_energyPoints();
	dt.get_attackDamage();
	std::cout << std::endl;

	dt.attack("Target1");
	dt.guardGate();
	dt.highFivesGuys();
	dt.whoAmI();

	std::cout << std::endl;
	dt.takeDamage(42);
	dt.beRepaired(10);
	dt.get_hitPoints();

	std::cout << std::endl;
	return 0;
}