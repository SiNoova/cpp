#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "--------" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "--------" << std::endl;
		std::vector<int> numbers;
		for (int i = 0; i <= 1000; ++i)
			numbers.push_back(i * 2);

		Span bigSpan(1001);
		bigSpan.addRange(numbers.begin(), numbers.end());
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

		std::cout << "--------" << std::endl;
		Span small(3);
		small.addNumber(1);
		small.addNumber(2);
		small.addNumber(3);
		small.addNumber(4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "--------" << std::endl;
		Span s(1);
		s.addNumber(5);
		std::cout << s.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
