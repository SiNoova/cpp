#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);

        std::vector<int>::const_iterator it1 = easyfind(vec, 30);
        std::cout << "Found in vector: " << *it1 << std::endl;

        easyfind(vec, 100);
    }
    catch (const std::exception& e) {
        std::cerr << "Vector error: " << e.what() << std::endl;
    }

    try {
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(10);
        lst.push_back(15);
        lst.push_back(20);

        std::list<int>::const_iterator it2 = easyfind(lst, 10);
        std::cout << "Found in list: " << *it2 << std::endl;

        easyfind(lst, 99);
    }
    catch (const std::exception& e) {
        std::cerr << "List error: " << e.what() << std::endl;
    }

    return 0;
}
