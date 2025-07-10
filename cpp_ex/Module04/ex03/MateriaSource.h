#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.h"
#include "AMateria.h"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materia[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria *m);
	AMateria *createMateria(const std::string &type);
};

#endif