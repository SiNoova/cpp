#include "PmergeMe.hpp"

int check_if_num(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}

int parse_nums(int size, char **av)
{
	for (int i = 1; i < size; i++)
	{
		if (!check_if_num(av[i]))
			return -1;
	}
	return 0;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Syntax error: ./PergeMe <integers>!" << std::endl;
		return 1;
	}
	if (parse_nums(ac, av))
	{
		std::cout << "Syntax error: invalid integer!" << std::endl;
		return 1;
	}
	std::vector<int> vect;
	for (int i = 1; i < ac; i++)
	{
		vect.push_back(std::atoi(av[i]));
	}
	std::cout << "vect: ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
	
	vect = pairing(vect, 1);
	if (!isitsorted(vect))
	{
		std::cout << "The vector is not sorted!" << std::endl;
		return 1;
	}
	std::cout << "The vector is sorted!" << std::endl;

	// std::vector<int> vect;
	// generate_jakobstald_sequence(vect, 7);
	std::cout << "sorted: ";
	for (size_t i = 0; i < vect.size(); i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
	return 0;
}