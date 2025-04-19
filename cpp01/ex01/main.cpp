#include "Zombie.hpp"

int main() {
    int N = 5;
    std::string name = "Walker";

    Zombie* horde = zombieHorde(N, name);
    if (!horde)
	{
        std::cerr << "Failed to create zombie horde!" << std::endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}