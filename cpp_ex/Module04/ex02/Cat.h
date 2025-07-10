#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat : public Animal
{
private:
	Brain *brainzz;

public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	~Cat();

	void makeSound() const;
	Brain *getBrain() const;
};

#endif