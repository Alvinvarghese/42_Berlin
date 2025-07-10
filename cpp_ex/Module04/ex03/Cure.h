#ifndef CURE_H
#define CURE_H

#include "AMateria.h"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();

	std::string const &getType() const;
	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif