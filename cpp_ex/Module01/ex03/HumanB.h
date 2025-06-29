#ifndef HUMANB_H_
#define HUMANB_H_

#include "Weapon.h"

class HumanB
{
	std::string nameB;
	Weapon *weaponB;

public:
	HumanB(std::string nameB);
	void setWeapon(Weapon &weaponB);
	// The setWeapon method allows HumanB to set its weapon.
	// This method takes a reference to a weapon object and assigns it to the weaponB pointer.
	// This allows HumanB to use the weapon later in the attack method.
	// The weaponB pointer is used to store the weapon that HumanB will use.
	// If the weaponB pointer is not set, the attack method will not output anything.
	// This allows HumanB to have a weapon that can be changed at runtime.
	// If the weaponB pointer is not set, the attack method will not output anything.

	void attack();
	~HumanB();
};

#endif