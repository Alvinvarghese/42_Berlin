#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

/*
int main()
{
	int num = 4;
	const Animal *animals[num];
	for (int i = 0; i < num; i++)
	{
		if (i % 2 == 0)
			{
				animals[i] = new Cat();
				std::cout << "Cat created at index " << i << std::endl;
				std::cout << std::endl;
			}
		else
			{
				animals[i] = new Dog();
				std::cout << "Dog created at index " << i << std::endl;
				std::cout << std::endl;
			}
	}

	for (int i = 0; i < num; i++)
	{
		animals[i]->makeSound();
	}

	// we can delete from 0 to num - 1 and also from num - 1 to 0

	for (int i = 0; i < num; i++)
	{
		std::cout << std:: endl;
		std::cout << "Deleting animal at index " << i << std::endl;
		std::cout << "Type: " << animals[i]->getType() << std::endl;
		delete animals[i];
	}
	return 0;
}
*/

int main()
{
	std::cout << "\n=== Deep Copy vs Shallow Copy Demo ===" << std::endl;
	Cat originalCat;
	std::cout << std::endl;

	Cat copyCat(originalCat); // Copy constructor (deep copy)
	std::cout << std::endl;

	Cat assignedCat;
	std::cout << std::endl;

	assignedCat = originalCat; // Assignment operator (deep copy)
	std::cout << std::endl;

	std::cout << "\nAddresses of Brain objects:" << std::endl;
	std::cout << "originalCat.brainzz: " << (void *)originalCat.getBrain() << std::endl;
	std::cout << "copyCat.brainzz:     " << (void *)copyCat.getBrain() << std::endl;
	std::cout << "assignedCat.brainzz: " << (void *)assignedCat.getBrain() << std::endl;

	std::cout << "\nIf these addresses are different, it's a deep copy.\nIf they are the same, it's a shallow copy." << std::endl;

	return 0;
}