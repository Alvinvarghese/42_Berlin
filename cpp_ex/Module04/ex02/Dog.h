#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog : public Animal
{
private:
	Brain	*brainzz;
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	~Dog();

	void makeSound() const;
};

#endif