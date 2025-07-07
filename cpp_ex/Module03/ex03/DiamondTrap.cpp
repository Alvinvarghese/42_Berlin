#include "DiamondTrap.h"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "Default DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	// hitPoints = FragTrap::hitPoints;	   // 100
	// energyPoints = ScavTrap::energyPoints; // 50
	// attackDamage = FragTrap::attackDamage; // 30
	std::cout << "DiamondTrap " << name << " is ready for action!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap assignment operator called." << std::endl;
	if (this != &other)
	{
		name = other.name;
		ClapTrap::name = other.name + "_clap_name";
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << name << " has been destroyed." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << name << " and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}

void DiamondTrap::get_hitPoints() const
{
	std::cout << "Hit Points: " << hitPoints << std::endl;
}

void DiamondTrap::get_energyPoints() const
{
	std::cout << "Energy Points: " << energyPoints << std::endl;
}

void DiamondTrap::get_attackDamage() const
{
	std::cout << "Attack Damage: " << attackDamage << std::endl;
}