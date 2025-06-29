#ifndef _CONTACT_H_
#define _CONTACT_H_
#include <string>
class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_num;
	std::string secret;

public:
	void set_firstname(std::string fname);
	void set_lastname(std::string lname);
	void set_nickname(std::string nname);
	void set_phonenum(std::string phnum);
	void set_secret(std::string secret);

	void set_contact();
	void get_contact();

	std::string get_firstname();
	std::string get_lastname();
	std::string get_nickname();
	std::string get_phonenum();
	std::string get_secret();
};

#endif