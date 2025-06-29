#include <iostream>
#include "Contact.h"

void Contact::set_contact()
{
}
void Contact::get_contact()
{
}
void Contact::set_firstname(std::string fname)
{
	first_name = fname;
}

std::string Contact::get_firstname()
{
	return first_name;
}

void Contact::set_lastname(std::string lname)
{
	last_name = lname;
}

std::string Contact::get_lastname()
{
	return last_name;
}

void Contact::set_nickname(std::string str)
{
	nickname = str;
}

std::string Contact::get_nickname()
{
	return nickname;
}

void Contact::set_phonenum(std::string phnum)
{
	phone_num = phnum;
}

std::string Contact::get_phonenum()
{
	return phone_num;
}

void Contact::set_secret(std::string secret)
{
	this->secret = secret;
}

std::string Contact::get_secret()
{
	return secret;
}