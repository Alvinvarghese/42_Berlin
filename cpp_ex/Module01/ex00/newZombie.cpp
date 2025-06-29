#include <iostream>
#include "Zombie.h"

Zombie *newZombie(std::string name)
{
	Zombie *dynamic_allocation = new Zombie(name);
	return dynamic_allocation;
}