#include "ClapTrap.h"

ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " is ready to fight!" << std::endl;
}

/*
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
	*this = other;
}
*/
ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name),
	  hitPoints(other.hitPoints),
	  energyPoints(other.energyPoints),
	  attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target
				  << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << name << " cannot attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > amount)
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount
				  << " points of damage! Remaining hit points: " << hitPoints << std::endl;
	}
	else
	{
		hitPoints = 0;
		std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints > 0 && hitPoints > 0)
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << name << " repairs itself for " << amount
				  << " points! Current hit points: " << hitPoints << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
	}
}