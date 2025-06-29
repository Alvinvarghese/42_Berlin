#include "FragTrap.h"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " is ready for action!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << name << " has been destroyed." << std::endl;
}

void FragTrap::highFivesGuys()
{
	if (hitPoints > 0)
	{
		std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << name << " cannot request a high five!" << std::endl;
	}
}

