#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_
#include "Contact.h"

class PhoneBook
{
private:
	Contact contact_list[8];
	int index;

public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void display_contact(int i);
	void display_contact_table();
	std::string input_details(std::string str);
	std::string truncate_string(std::string str);
	void search_contact();
	int get_search_contact_input();
};

#endif