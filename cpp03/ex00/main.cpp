#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1;
    ClapTrap clap2("Warrior");
    ClapTrap clap3(clap2);

    clap1 = clap2;

    std::cout << "--- Attack tests ---" << std::endl;
    clap1.attack("Enemy1");
    clap2.attack("Enemy2");
    clap3.attack("Enemy3");

    std::cout << "--- Take damage tests ---" << std::endl;
    clap1.takeDamage(5);
    clap2.takeDamage(15);
    clap3.takeDamage(3);

    std::cout << "--- Repair tests ---" << std::endl;
    clap1.beRepaired(4);
    clap2.beRepaired(2);
    clap3.beRepaired(6);
	
    std::cout << "--- Energy Depletion Test ---" << std::endl;

    for (int i = 0; i < 11; ++i)
		clap1.attack("Dummy Target");
    clap1.beRepaired(4);

    return 0;
}
