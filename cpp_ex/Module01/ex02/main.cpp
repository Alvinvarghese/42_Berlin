#include <iostream>
#include <string>

int main()
{
	std::string var = "HI THIS IS BRAIN";

	std::string *stringPTR = &var;
	std::string &stringREF = var;
	std::cout << "value of var                  : " << var << std::endl;
	std::cout << "mem address of var            : " << &var << std::endl;
	std::cout << "value pointed to by stringREF : " << stringREF << std::endl;
	std::cout << "mem address held by stringREF : " << &stringREF << std::endl;
	std::cout << "value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "mem address held by stringPTR : " << stringPTR << std::endl;
	std::cout << "mem address of sttringPTR     : " << &stringPTR << std::endl;
	return 0;
}