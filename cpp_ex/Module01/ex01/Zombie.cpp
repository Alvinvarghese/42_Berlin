#include <iostream>
#include "Zombie.h"

Zombie::Zombie()
{
}

void Zombie::setName(std::string name)
{
	this->name = name;
	//std::cout << this->name << " Created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->name << " Died" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}