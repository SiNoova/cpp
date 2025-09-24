#include "iter.hpp"
#include <string>

// A simple print function for generic types
template <typename T>
void printElement(T const &x) {
    std::cout << x << " ";
}

int main() {
    int arrInt[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(arrInt, 5, printElement<int>);
    std::cout << std::endl;

    std::string arrStr[] = {"hello", "world", "iter", "test"};
    std::cout << "String array: ";
    iter(arrStr, 4, printElement<std::string>);
    std::cout << std::endl;

    const double arrDouble[] = {3.14, 2.71, 1.41};
    std::cout << "Const double array: ";
    iter(arrDouble, 3, printElement<double>);
    std::cout << std::endl;

    return 0;
}
