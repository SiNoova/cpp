#include "FragTrap.hpp"

int main()
{
    FragTrap frag1;
    FragTrap frag2("Destroyer");
    FragTrap frag3(frag2);

    // Copy assignment
    frag1 = frag2;

    std::cout << "--- Attack tests ---" << std::endl;
    frag1.attack("Enemy1");
    frag2.attack("Enemy2");   
    frag3.attack("Enemy3");   

    std::cout << "--- Take damage tests ---" << std::endl;
    frag1.takeDamage(5);  
    frag2.takeDamage(15);  
    frag3.takeDamage(3);

    std::cout << "--- Repair tests ---" << std::endl;
    frag1.beRepaired(4);
    frag2.beRepaired(2);
    frag3.beRepaired(6);

    std::cout << "--- High Five test ---" << std::endl;
    frag1.highFivesGuys();
    frag2.highFivesGuys();
    frag3.highFivesGuys();

    return 0;
}
