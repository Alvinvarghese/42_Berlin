#include "Animal.h"

Animal::Animal() : type("Unknown")
{
	std::cout << "Default Animal created with type: " << type << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copied with type: " << type << std::endl;
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called for type: " << type << std::endl;
}

/* 
// MakeSound is a pure virtual function
// and must be defined in derived classes.

void Animal::makeSound() const
{
	std::cout << "Animal make sound is called" << std::endl;
}
*/

void Animal::setType(const std::string &type)
{
	this->type = type;
}

std::string Animal::getType() const
{
	return type;
}
