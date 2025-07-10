#include "AMateria.h"
#include "ICharacter.h"

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria(const AMateria &other) : type(other.type) {}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		// type = other.type; // The `type` should only be set in the constructor and never changed by assignment.
	}
	return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "Using " << type << " on " << target.getName() << std::endl;
}