
#include <iostream>
#include <sstream>
#include "Zombie.h"


Zombie *zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return nullptr;
	Zombie *newZombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << name << "_" << (i + 1);
		newZombieHorde[i].setName(ss.str());
	}
	return newZombieHorde;
}
