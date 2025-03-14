#include "PhoneBook.hpp"

int is_string_empty(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] != ' ' && str[i] != '\t')
		|| (str[i] < 32 || str[i] > 126))
			return (0);
	}
	return (1);
}

int has_only_printable_characters(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
	}
	return (1);
}

int no_letters(std::string str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
			return (1);
	}
	return (0);
}

void PhoneBook::add(int i)
{
	std::string prompt;

	/*--------------------------*/
	CHECKPOINT:
	std::cout << "enter first name: ";
	if (std::getline(std::cin, prompt).eof())
		fexit();
	if (prompt.empty() || is_string_empty(prompt) || !has_only_printable_characters(prompt))
		goto CHECKPOINT;
	contacts[i].edit_first_name(prompt);
	/*--------------------------*/
	CHECKPOINT2:
	std::cout << "enter last name: ";
	if (std::getline(std::cin, prompt).eof())
		fexit();	
	if (prompt.empty() || is_string_empty(prompt) || !has_only_printable_characters(prompt))
		goto CHECKPOINT2;
	contacts[i].edit_last_name(prompt);
	/*--------------------------*/
	CHECKPOINT3:
	std::cout << "enter nickname: ";
	if (std::getline(std::cin, prompt).eof())
		fexit();
	if (prompt.empty() || is_string_empty(prompt) || !has_only_printable_characters(prompt))
		goto CHECKPOINT3;
	contacts[i].edit_nickname(prompt);
	/*--------------------------*/
	CHECKPOINT4:
	std::cout << "enter phone number: ";
	if (std::getline(std::cin, prompt).eof())
		fexit();
	if (prompt.empty() || is_string_empty(prompt) || !has_only_printable_characters(prompt) || no_letters(prompt))
		goto CHECKPOINT4;
	contacts[i].edit_phone_number(prompt);
	/*--------------------------*/
	CHECKPOINT5:
	std::cout << "enter darkest secret: ";
	if (std::getline(std::cin, prompt).eof())
		fexit();
	if (prompt.empty() || is_string_empty(prompt) || !has_only_printable_characters(prompt))
		goto CHECKPOINT5;
	contacts[i].edit_darkest_secret(prompt);
	if (size != 8)
		size = i + 1;
}

void PhoneBook::search()
{
	int i = 0;
	std::string prompt;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|    f_name|    l_name|  nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	while (i < size)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		int len = contacts[i].get_first_name().length();
		if (len < 10)
			std::cout << std::setw(10) << contacts[i].get_first_name() << "|";
		else
			std::cout << contacts[i].get_first_name().substr(0, 9) + ".|";
		len = contacts[i].get_last_name().length();
		if (len < 10)
			std::cout << std::setw(10) << contacts[i].get_last_name() << "|";
		else
			std::cout << contacts[i].get_last_name().substr(0, 9) + ".|";
		len = contacts[i].get_nickname().length();
		if (len < 10)
			std::cout << std::setw(10) << contacts[i].get_nickname() << "|" << std::endl;
		else
			std::cout << contacts[i].get_nickname().substr(0, 9) + ".|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		i++;
	}
	std::cout << "enter an index: ";
	INDEX:
	if (std::getline(std::cin, prompt).eof())
		fexit();
	i = prompt[0] - '0';
	if (prompt.empty() || is_string_empty(prompt) || !has_only_printable_characters(prompt) 
		||prompt.length() > 1 || i >= size)
	{
		std::cout << "enter a valid index: ";
		goto INDEX; 
	}
	std::cout << "first name: " << contacts[i].get_first_name() << std::endl;
	std::cout << "last name: " << contacts[i].get_last_name() << std::endl;
	std::cout << "nickname: " << contacts[i].get_nickname() << std::endl;
	std::cout << "phone number: " << contacts[i].get_phone_number() << std::endl;
	std::cout << "darkest secret: " << contacts[i].get_darkest_secret() << std::endl;
}

void PhoneBook::fexit()
{
	exit(0);
}