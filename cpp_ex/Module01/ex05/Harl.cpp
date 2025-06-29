#include "Harl.h"

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for it!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/*
the syntax `void (Harl::*)()` describes a pointer to a member function of `Harl` that returns `void` and takes no parameters.

The array `functions` holds pointers to the member functions of the `Harl` class. Each element in the array corresponds to a specific complaint level, allowing you to call the appropriate function based on the input level.

To use one of these function pointers, you need an instance of `Harl`, and you call the function like this: `(instance.*functions[i])();`, where `instance` is an object of type `Harl` and `i` is the index of the function you want to call.
eg::  Harl harlfn;
	(harlfn.*functions[3])();

This technique is useful for implementing things like command dispatch tables or mapping strings to functions without using a long series of `if` or `switch` statements.

*/

void Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}

	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}