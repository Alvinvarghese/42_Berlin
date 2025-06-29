#ifndef HUMANA_H_
#define HUMANA_H_

#include "Weapon.h"

class HumanA
{
	std::string nameA;
	Weapon &weaponA;

public:
	HumanA(std::string nameA, Weapon &weaponA);
	void attack();
	~HumanA();
};

#endif