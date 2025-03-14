#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phone_number();
		std::string get_darkest_secret();
		void edit_first_name(std::string name);
		void edit_last_name(std::string name);
		void edit_nickname(std::string name);
		void edit_phone_number(std::string name);
		void edit_darkest_secret(std::string name);
};



#endif