#include <iostream>
#include <string>
#include "PhoneBook.h"

int main(void)
{
	std::string menu;
	PhoneBook phn_bk;
	while (1)
	{
		std::cout << "\nEnter any of the Command:" << std::endl;
		std::cout << "ADD\nSEARCH\nEXIT" << std::endl;
		// std::cout << "Waiting for Response:  ";
		getline(std::cin, menu);
		// std::cin >> menu;
		if (menu.compare("ADD") == 0 || menu.compare("add") == 0)
			phn_bk.add_contact();
		else if (menu.compare("SEARCH") == 0 || menu.compare("search") == 0)
			phn_bk.search_contact();
		else if (menu.compare("EXIT") == 0 || menu.compare("exit") == 0)
			break;
		else
			std::cout << "\t!!! Wrong input !!!" << std::endl;
	}
	return 0;
}
