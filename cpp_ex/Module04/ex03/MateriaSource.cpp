#include "MateriaSource.h"
#include <iostream>

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other.materia[i])
			materia[i] = other.materia[i]->clone();
		else
			materia[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete materia[i];
			if (other.materia[i])
				materia[i] = other.materia[i]->clone();
			else
				materia[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (materia[i])
			delete materia[i];
		materia[i] = NULL; // Ensure no dangling pointers
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!materia[i])
		{
			materia[i] = m;
			return;
		}
	}
	std::cout << "MateriaSource: No space to learn new materia." << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	}
	std::cout << "MateriaSource: Materia of type '" << type << "' not found." << std::endl;
	return NULL;
}