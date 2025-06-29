#include "ClapTrap.h"

int main()
{
	ClapTrap claptrap("CLTP");

	claptrap.attack("TARGET1");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	std::cout << std::endl;

	claptrap.attack("TARGET2");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);
	std::cout << std::endl;

	claptrap.attack("TARGET3");
	claptrap.takeDamage(15);
	claptrap.beRepaired(10);
	return 0;
}