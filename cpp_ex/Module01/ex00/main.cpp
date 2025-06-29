#include <iostream>
#include "Zombie.h"

int main(void)
{

	Zombie stack("qwertz");
	stack.announce();

	Zombie *heap = newZombie("asdfgh");
	heap->announce();
	delete heap;

	randomChump("zxcvbn");
	return 0;
}
