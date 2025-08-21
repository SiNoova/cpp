#include "ScalarConverter.hpp"

int check_if_nums(std::string str, int num_type)
{
	bool point_flag = false;

	for (int i = 0; str[i]; i++)
	{
		if (str[0] == '.')
			return (0);
		if (num_type == 1 && i == str.size() - 1 && str[i] == 'f')
			break;
		if (num_type && !point_flag && str[i] == '.' && str[i + 1] != 'f' && i != str.size() - 1)
		{
			point_flag = true;
			continue;
		}	
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (0);
	}
	return (1);
}

void ScalarConverter::convert(const std::string &literal)
{
	int pos = literal.find('f');
	int point_pos = literal.find('.');

	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		std::cout << "its a float!!" << std::endl;
	else if (literal == "+inf" || literal == "-inf" || literal == "nan")
		std::cout << "its a double!!" << std::endl;
	else if (literal.length() == 1 && (literal[0] < '0' || literal[0] > '9'))
		std::cout << "its a char!!" << std::endl;
	else if (pos == std::string::npos && point_pos == std::string::npos && check_if_nums(literal, 0))
		std::cout << "its a int!!" << std::endl;
	else if (pos != std::string::npos && point_pos != std::string::npos && check_if_nums(literal, 1))
		std::cout << "its a float!!" << std::endl;
	else if (check_if_nums(literal, 3))
		std::cout << "its a double!!" << std::endl;
	else
		std::cout << "Error!!" << std::endl;

}