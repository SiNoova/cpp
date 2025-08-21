#include "ScalarConverter.hpp"

int check_if_nums(std::string str, int num_type)
{
	bool point_flag = false;

	if (str.empty())
		return (0);
	for (int i = 0; str[i]; i++)
	{
		if (str[0] == '.')
			return (0);
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
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

int detect_type(const std::string &literal)
{
	int pos = literal.find('f');
	int point_pos = literal.find('.');

	if (literal == "+inff" || literal == "-inff" || literal == "nanf")
		return (1);
	else if (literal == "+inf" || literal == "-inf" || literal == "nan")
		return (2);
	else if (literal.length() == 1 && (literal[0] < '0' || literal[0] > '9'))
		return (3);
	else if (pos == std::string::npos && point_pos == std::string::npos && check_if_nums(literal, 0))
		return (4);
	else if (pos != std::string::npos && point_pos != std::string::npos && check_if_nums(literal, 1))
		std::cout << "its a float!!" << std::endl;
	else if (check_if_nums(literal, 3))
		std::cout << "its a double!!" << std::endl;
	else
		std::cout << "Error!!" << std::endl;
	return 0;
}

void ScalarConverter::convert(const std::string &literal)
{
	int type = detect_type(literal);

		switch (type)
		{
			case 1:
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << literal << std::endl;
				std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
				break;
			}
			case 2:
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << literal << "f" << std::endl;
				std::cout << "double: " << literal << std::endl;
				break;
			}
			case 3:
			{
				char a = literal[0];
				std::cout << "char: " << a << std::endl;
				std::cout << "int: " << static_cast<int>(a) << std::endl;
				std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(a) << "f" << std::endl;
				std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(a) << std::endl;
			}
			case 4:
			{
				int a;
				std::stringstream ss(literal);
				ss >> a;
				std::cout << a;
				return;
				if (isprint(a))
					std::cout << "char: " << "\'" << static_cast<char>(a) << "\'" << std::endl;
				else
					std::cout << "char: " << "Non displayable" << std::endl;
			}
		}
}
