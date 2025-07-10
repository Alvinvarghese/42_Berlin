#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include "Brain.h"

class Animal
{
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() const = 0; // Pure virtual function
	void setType(const std::string &type);
	std::string getType() const;

protected:
	std::string type;
};

#endif