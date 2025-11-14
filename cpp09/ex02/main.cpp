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
		std::cout << "Syntax error: ./PmergeMe <integers>!" << std::endl;
        return 1;
    }
	
    if (parse_nums(ac, av)) 
    {
		std::cout << "Syntax error: invalid integer!" << std::endl;
        return 1;
	}

	clock_t start = std::clock();
    std::vector<int> vect;
    for (int i = 1; i < ac; i++)
		vect.push_back(atoi(av[i]));
	std::vector<int> pre_sorted = vect;
	
    vect = pairing(vect, 1); 
	clock_t end = std::clock();

	std::cout << "Before: ";
	for (size_t i = 0; i < pre_sorted.size(); i++)
		std::cout << pre_sorted[i] << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < vect.size(); i++)
        std::cout << vect[i] << " ";
    std::cout << std::endl;

    double duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << vect.size() 
              << " elements with std::vector: " << duration << " us" << std::endl;

	start = std::clock();
	std::deque<int> vect2;
	for (int i = 1; i < ac; i++)
		vect2.push_back(atoi(av[i]));
			  
    vect2 = pairing(vect2, 1);
	end = std::clock();

    duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << vect2.size() 
              << " elements with std::deque: " << duration << " us" << std::endl;

    return 0;
}
