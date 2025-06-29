#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;
	Cat x;
	Cat z(x);
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete i;
	delete j;
	// delete meta;

	std::cout << "---------------------------" << std::endl;
	const WrongAnimal *wrongMeta = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;

	std::cout << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}