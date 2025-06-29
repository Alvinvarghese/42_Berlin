#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
public:
	Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();

	virtual void makeSound() const;
	void setType(const std::string &type);
	std::string getType() const;

protected:
	std::string type;
};

#endif