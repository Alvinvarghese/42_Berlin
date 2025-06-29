#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	void setName(std::string name);
	~Zombie();
	void announce(void);
};

Zombie *zombieHorde(int N, std::string name);

#endif
