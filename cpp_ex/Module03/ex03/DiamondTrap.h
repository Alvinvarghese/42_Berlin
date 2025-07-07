#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "ScavTrap.h"
#include "FragTrap.h"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();

	void whoAmI();

	void get_hitPoints() const;
	void get_energyPoints() const;
	void get_attackDamage() const;

private:
	std::string name;
};

#endif