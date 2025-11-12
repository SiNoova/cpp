#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	(void) av;
	if (ac != 2)
	{
		std::cout << "Syntax error: ./btc /path/to/file !" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc;
		btc.ProcessInput(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}