#include "MutantStack.hpp"
#include <iostream>

int main() {
    // Create a MutantStack of int
    MutantStack<int> mstack;

    // Push some elements
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);

    // Iterate using iterator (forward)
    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Iterate using reverse_iterator
    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Using const_iterator
    const MutantStack<int>& constStack = mstack;
    std::cout << "Const forward iteration: ";
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    return 0;
}
