#include "Dog.h"

Dog::Dog()
{
	type = "Dog";
	brainzz = new Brain();
	std::cout << "Dog created with type: " << type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copied with type: " << type << std::endl;
	std::cout << "Dog Copy constructor called" << std::endl;
	brainzz = new Brain(*other.brainzz); // Deep copy: create a new Brain object
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other); // Call base class assignment operator
		// Check if brainzz is already allocated
		if (brainzz != NULL)
			delete brainzz;					 // Delete old brainzz
		brainzz = new Brain(*other.brainzz); // Deep copy: create a new Brain object
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called for type: " << type;
	std::cout << " and brainzz also deleted" << std::endl;
	delete brainzz;
}

void Dog::makeSound() const
{
	std::cout << "Dog barks" << std::endl;
}
