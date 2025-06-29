#ifndef WEAPON_H_
#define WEAPON_H_

#include <string>

class Weapon
{
	std::string type;

public:
	Weapon();
	Weapon(std::string type);
	const std::string &getType();
	void setType(std::string type);
	~Weapon();
};

#endif