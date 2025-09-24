#include <iostream>
#include "Array.hpp"

template <typename T>
void printArray(const Array<T>& arr) {
    std::cout << "[ ";
    for (size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << "]" << std::endl;
}

int main() {
    try {
        std::cout << "---- Default constructor ----" << std::endl;
        Array<int> empty;
        std::cout << "Empty size: " << empty.size() << std::endl;

        std::cout << "\n---- Constructor with size ----" << std::endl;
        Array<int> numbers(5);
        for (size_t i = 0; i < numbers.size(); i++)
            numbers[i] = static_cast<int>(i * 10);
        printArray(numbers);

        std::cout << "\n---- Copy constructor ----" << std::endl;
        Array<int> copy(numbers);
        copy[0] = 999;
        std::cout << "Original: ";
        printArray(numbers);
        std::cout << "Copy:     ";
        printArray(copy);

        std::cout << "\n---- Assignment operator ----" << std::endl;
        Array<int> assigned;
        assigned = numbers;
        assigned[1] = 555;
        std::cout << "Original: ";
        printArray(numbers);
        std::cout << "Assigned: ";
        printArray(assigned);

        std::cout << "\n---- Const access ----" << std::endl;
        const Array<int> constArray(numbers);
        std::cout << "constArray[2] = " << constArray[2] << std::endl;

        std::cout << "\n---- Out of bounds ----" << std::endl;
        std::cout << numbers[10] << std::endl; 

    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
