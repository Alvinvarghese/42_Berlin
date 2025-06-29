#include <iostream>
#include "HumanA.h"
#include "Weapon.h"

// References must be initialized in the member initializer list
//  and cannot be assigned in the constructor body.
//  References must be initialized when they are created,
//  and they cannot be changed to refer to a different object later.

HumanA::HumanA(std::string name, Weapon &weapon_name)
	: nameA(name), weaponA(weapon_name)
{
}

// {
// 	this->nameA = name;
// 	this->weaponA = weapon_name;
// }

void HumanA::attack()
{
	std::cout << this->nameA << " attacks with their " << this->weaponA.getType() << std::endl;
}

HumanA::~HumanA()
{
}