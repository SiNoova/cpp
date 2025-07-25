#include "PhoneBook.hpp"

int main()
{
	std::string prompt;
	PhoneBook phone;
	int i;

	i = 0;
	std::cout << "ADD: add a contact" << std::endl;
	std::cout << "SEARCH: shows a list of all contacts" << std::endl;
	std::cout << "EXIT: exit the program" << std::endl;
	while (1)
	{
		std::cout << "->";
		if (i == 8)
			i = 0;
		if (std::getline(std::cin, prompt).eof())
			phone.fexit();
		if (prompt == "ADD")
		{
			phone.add(i);
			i++;
		}
		else if (prompt == "SEARCH")
			phone.search();
		else if (prompt == "EXIT")
			phone.fexit();
		else
			std::cout << "enter a valid command." << std::endl;
	}
}