#include "DiamondTrap.hpp"

int main()
{
    // Create DiamondTraps
    DiamondTrap diamond1("DiamondTrap1");    
    DiamondTrap diamond2;
    DiamondTrap diamond3(diamond1);

    // Copy assignment
    diamond2 = diamond1;

    std::cout << "--- Attack tests ---" << std::endl;
    diamond1.attack("Enemy1");
    diamond2.attack("Enemy2");
    diamond3.attack("Enemy3");

    std::cout << "--- Take damage tests ---" << std::endl;
    diamond1.takeDamage(5);
    diamond2.takeDamage(15);
    diamond3.takeDamage(3);

    std::cout << "--- Repair tests ---" << std::endl;
    diamond1.beRepaired(4);
    diamond2.beRepaired(2);
    diamond3.beRepaired(6);

    std::cout << "--- High Five test ---" << std::endl;
    diamond1.highFivesGuys();
    diamond2.highFivesGuys();

    std::cout << "--- Who Am I test ---" << std::endl;
    diamond1.whoAmI();
    diamond2.whoAmI();

    return 0;
}
