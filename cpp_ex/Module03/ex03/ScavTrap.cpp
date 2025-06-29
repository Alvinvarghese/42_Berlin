#include "ScavTrap.h"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " is ready to guard the gate!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " has been destroyed." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
	{
		std::cout << "ScavTrap " << name << " cannot attack!" << std::endl;
	}
}

void ScavTrap::guardGate()
{
	if (hitPoints > 0)
	{
		std::cout << "ScavTrap " << name << " is now in Gate Keeper mode!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << name << " cannot guard the gate!" << std::endl;
	}
}
