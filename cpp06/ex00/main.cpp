#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	std::string test(av[1]);
	ScalarConverter::convert(test);
}