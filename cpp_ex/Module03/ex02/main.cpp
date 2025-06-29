#include "FragTrap.h"

int main()
{
	FragTrap fragTrap("Fraggy");
	std::cout << std::endl;
	fragTrap.attack("-->target1<--");
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(5);
	fragTrap.beRepaired(3);
	std::cout << std::endl;
	fragTrap.attack("-->target2<--");
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(100);
	fragTrap.beRepaired(10);
	fragTrap.highFivesGuys();
	std::cout << std::endl;
	return 0;
}