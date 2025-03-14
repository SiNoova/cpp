#include "Contact.hpp"

std::string Contact::get_first_name(void)
{
	return first_name;
}

std::string Contact::get_last_name(void)
{
	return last_name;
}
std::string Contact::get_nickname(void)
{
	return nickname;
}
std::string Contact::get_phone_number(void)
{
	return phone_number;
}

std::string Contact::get_darkest_secret(void)
{
	return darkest_secret;
}

void Contact::edit_first_name(std::string name)
{
	first_name = name;
}

void Contact::edit_last_name(std::string name)
{
	last_name = name;
}

void Contact::edit_nickname(std::string name)
{
	nickname = name;
}

void Contact::edit_phone_number(std::string name)
{
	phone_number = name;
}

void Contact::edit_darkest_secret(std::string name)
{
	darkest_secret = name;
}

