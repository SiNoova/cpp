#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "invalid args!!" << std::endl;
		return 1;
	}
	std::string level(av[1]);
	int index;
	Harl test;

	index = -1;
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	for (int i = 0; i < 4; ++i) {
		if (level == levels[i]) {
			index = i;
		}
	}

	switch (index) {
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
            std::cout << "[ DEBUG ]" << std::endl;
			test.complain("DEBUG");
			std::cout << std::endl;
			// Fall through

		case 1:
            std::cout << "[ INFO ]" << std::endl;
			test.complain("INFO");
			std::cout << std::endl;
			// Fall through
		case 2:
            std::cout << "[ WARNING ]" << std::endl;
			test.complain("WARNING");
			std::cout << std::endl;
			// Fall through
		case 3:
            std::cout << "[ ERROR ]" << std::endl;
			test.complain("ERROR");
			std::cout << std::endl;
			// Fall through
    }
    
}