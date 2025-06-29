#include <string>
#include <iostream>
#include <limits>
#include <sstream> // the stringstream header
#include <iomanip> // setw
#include "PhoneBook.h"

PhoneBook::PhoneBook() : index(-1)
{
	// index = -1;
}

PhoneBook::~PhoneBook()
{
}

std::string PhoneBook::input_details(std::string field)
{
	std::string str;
	int ph;
	do
	{
		ph = 0;
		std::cout << "Enter " << field << " : " << std::endl;
		getline(std::cin, str);
		if (str.empty())
			std::cout << field << " cannot be empty :" << std::endl;
		if (field.compare("Phone Number") == 0)
		{
			for (size_t j = 0; j < str.length(); j++)
			{
				if (!std::isdigit(str[j]))
				{
					ph = 1;
					std::cout << field << " Needed to be numeric :" << std::endl;
					break;
				}
			}
		}
	} while (str.empty() || ph);
	return str;
}

void PhoneBook::display_contact(int i)
{
	std::cout << "\nFirst Name = " << contact_list[i].get_firstname() << std::endl;
	std::cout << "Last Name = " << contact_list[i].get_lastname() << std::endl;
	std::cout << "Nick Name = " << contact_list[i].get_nickname() << std::endl;
	std::cout << "Phone Number = " << contact_list[i].get_phonenum() << std::endl;
	std::cout << "Secret = " << contact_list[i].get_secret() << std::endl;
}

void PhoneBook::add_contact()
{
	if (index < 7)
		index++;
	else
		index = 0;

	std::string str;
	str = input_details("First Name");
	contact_list[index].set_firstname(str);

	str = input_details("Last Name");
	contact_list[index].set_lastname(str);

	str = input_details("Nick Name");
	contact_list[index].set_nickname(str);

	str = input_details("Phone Number");
	contact_list[index].set_phonenum(str);

	str = input_details("Your Secret");
	contact_list[index].set_secret(str);
}

/*
	Convert the string to an integer using stringstream
	std::stringstream ss(i);
*/

int PhoneBook::get_search_contact_input()
{
	int j = -1;
	do
	{
		std::string i;
		display_contact_table();
		std::cout << "Enter an index from the table to display : " << std::endl;
		getline(std::cin, i);

		std::stringstream ss(i);
		ss >> j;

		if (j > index)
			std::cout << "No contact exist \n Please try again" << std::endl;
		if (j > 7 || j < 0)
			std::cout << "Please enter a num b/w 0 - 7" << std::endl;
	} while (j > index || j > 7 || j < 0);
	return j;
}

void PhoneBook::search_contact()
{
	int roll;
	if (index == -1)
		std::cout << "!!!Please enter a contact and search!!!" << std::endl;
	else
	{
		roll = get_search_contact_input();
		display_contact(roll);
	}
}

std::string PhoneBook::truncate_string(std::string str)
{
	if (str.length() > 10)
	{
		return str.substr(0, 9) + '.';
	}
	return str;
}

void PhoneBook::display_contact_table()
{
	std::string str;

	std::cout << std::endl;

	std::cout << std::setfill('-') << std::setw(45) << std::flush;
	std::cout << "-" << std::endl;

	std::cout << "|" << std::setfill(' ') << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;

	std::cout << std::setfill('-') << std::setw(45) << std::flush;
	std::cout << "-" << std::endl;

	for (int i = 0; i <= index; i++)
	{
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i;
		str = truncate_string(contact_list[i].get_firstname());
		std::cout << "|" << std::setw(10) << str;
		std::cout << "|" << std::setw(10) << truncate_string(contact_list[i].get_lastname());
		std::cout << "|" << std::setw(10) << truncate_string(contact_list[i].get_nickname());
		std::cout << "|" << std::endl;

		std::cout << std::setfill('-') << std::setw(45) << std::flush;
		std::cout << "-" << std::endl;
	}
}
