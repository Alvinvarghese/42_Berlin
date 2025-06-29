#include "ScavTrap.h"

int main()
{
	ScavTrap scavTrap("Guardian");
	std::cout << std::endl;
	scavTrap.attack("-->Enemy<--");
	scavTrap.guardGate();
	scavTrap.takeDamage(5);
	scavTrap.beRepaired(3);
	std::cout << std::endl;
	scavTrap.attack("-->Another Enemy<--");
	scavTrap.guardGate();
	scavTrap.takeDamage(100);
	scavTrap.beRepaired(50);
	std::cout << std::endl;
	scavTrap.attack("---Final Enemy---");
	scavTrap.guardGate();
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(5);
	std::cout << std::endl;
	return 0;
}