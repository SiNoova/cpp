#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    try {
        std::vector<int> vec = {10, 20, 30, 40, 50};
        auto it1 = easyfind(vec, 30);
        std::cout << "Found in vector: " << *it1 << std::endl;

        easyfind(vec, 100);
    }
    catch (const std::exception& e) {
        std::cerr << "Vector error: " << e.what() << std::endl;
    }

    try {
        std::list<int> lst = {5, 10, 15, 20};
        auto it2 = easyfind(lst, 10);
        std::cout << "Found in list: " << *it2 << std::endl;

        easyfind(lst, 99);
    }
    catch (const std::exception& e) {
        std::cerr << "List error: " << e.what() << std::endl;
    }

    return 0;
}
