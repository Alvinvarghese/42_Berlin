#include <iostream>
#include "HumanB.h"
#include "Weapon.h"

HumanB::HumanB(std::string name)
{
	this->nameB = name;
	this->weaponB = nullptr; // Initialize weaponB to nullptr
}

void HumanB::setWeapon(Weapon &weaponB)
{
	this->weaponB = &weaponB;
}

void HumanB::attack()
{
	if (this->weaponB)
		std::cout << this->nameB << " attacks with their " << this->weaponB->getType() << std::endl;
	else
		std::cout << this->nameB << " has no weapon to attack with!" << std::endl;
}

HumanB::~HumanB()
{
}