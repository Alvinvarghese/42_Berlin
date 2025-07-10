#include "Brain.h"

Brain::Brain()
{
	std::cout << "Brain --> Default Constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain --> Copy Constructor" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	if(this != &other)
	{
		for(int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain --> Assignment Operator" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain --> Destructor" << std::endl;
}