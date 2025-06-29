#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() : type("Unknown")
{
	std::cout << "Default WrongAnimal created with type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "Copy WrongAnimal created with type: " << type << std::endl;
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called for type: " << type << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound\n";
}
