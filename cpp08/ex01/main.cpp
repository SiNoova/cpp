#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()

int main()
{
    try {
        std::cout << "===== Official test =====" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << "\n===== Large test (10,000 numbers) =====" << std::endl;
        Span bigSpan(10000);

        // Fill with 10,000 random numbers
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        for (int i = 0; i < 10000; ++i)
            bigSpan.addNumber(std::rand() % 1337);

        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

        std::cout << "\n===== Range insert test =====" << std::endl;
        std::vector<int> range;
        for (int i = 0; i < 1000; ++i)
            range.push_back(i * 5);  // predictable spacing

        Span rangeSpan(1000);
        rangeSpan.addRange(range.begin(), range.end());

        std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
