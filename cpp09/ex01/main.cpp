#include "RPN.hpp"

int main(int ac , char **av)
{
	if (ac != 2)
	{
		std::cout << "Syntax error: ./RPN \"Reverse polish notaion\"" << std::endl;
		return 1;
	}
	std::string str(av[1]);
	RPN::Reverse_polish_notaion(str);
}