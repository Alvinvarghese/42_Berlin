#include<iostream>
#include "Zombie.h"

void randomChump(std::string name)
{
	Zombie randomStackZombie(name);
	randomStackZombie.announce();
}