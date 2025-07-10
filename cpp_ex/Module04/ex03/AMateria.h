#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>

class ICharacter; // Forward declaration of ICharacter
// Forward declaration to avoid circular dependency


class AMateria
{
protected:
	std::string type;

public:
	AMateria(const std::string &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const &getType() const;
	
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif