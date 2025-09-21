#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Number of arguments is not correct!" << std::endl;
		return 1;
	}
	std::string input(av[1]);
	ScalarConverter::convert(input);
}