#include <iostream>
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(10);
    Fixed c(2.5f);
    Fixed d = b;

    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << a <<  std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

    // Arithmetic
    std::cout << "Arithmetic operations:" << std::endl;
    std::cout << "b + c: " << b + c << std::endl;
    std::cout << "b - c: " << b - c << std::endl;
    std::cout << "b * c: " << b * c << std::endl;
    std::cout << "b / c: " << b / c << std::endl << std::endl;

    // Comparison
    std::cout << "Comparison operations:" << std::endl;
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl << std::endl;

    // Increments/Decrements
    std::cout << "Increment and decrement:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl << std::endl;

    // Min / Max
    Fixed e(100);
    Fixed f(42.42f);

    std::cout << "Min and max:" << std::endl;
    std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
    std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;

    return 0;
}
