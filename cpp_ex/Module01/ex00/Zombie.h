#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string name);
	~Zombie();
	void announce(void);
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
