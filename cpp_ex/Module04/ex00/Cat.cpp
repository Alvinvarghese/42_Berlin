#include "Cat.h"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat created with type: " << type << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copied with type: " << type << std::endl;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called for type: " << type << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat meows" << std::endl;
}
