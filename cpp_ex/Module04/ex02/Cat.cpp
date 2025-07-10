#include "Cat.h"

Cat::Cat()
{
	type = "Cat";
	brainzz = new Brain();
	std::cout << "Cat created with type: " << type << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copied with type: " << type << std::endl;
	std::cout << "Cat Copy constructor called" << std::endl;
	brainzz = new Brain(*other.brainzz);
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		if (brainzz != NULL)
			delete brainzz;
		brainzz = new Brain(*other.brainzz);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called for type: " << type;
	std::cout << " and brainzz also deleted" << std::endl;
	delete brainzz;
}

void Cat::makeSound() const
{
	std::cout << "Cat meows" << std::endl;
}

Brain *Cat::getBrain() const
{
	return brainzz;
}