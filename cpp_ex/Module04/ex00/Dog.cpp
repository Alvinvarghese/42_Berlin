#include "Dog.h"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog created with type: " << type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copied with type: " << type << std::endl;
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called for type: " << type << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog barks" << std::endl;
}
