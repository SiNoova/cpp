#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav1;
    ScavTrap scav2("Guardian");
    ScavTrap scav3(scav2);

    scav1 = scav2;

    std::cout << "--- Attack tests ---" << std::endl;
    scav1.attack("Enemy1");
    scav2.attack("Enemy2");
    scav3.attack("Enemy3");

    std::cout << "--- Take damage tests ---" << std::endl;
    scav1.takeDamage(50);    
    scav2.takeDamage(150);   
    scav3.takeDamage(30);      

    std::cout << "--- Repair tests ---" << std::endl;
    scav1.beRepaired(4);
    scav2.beRepaired(2);
    scav3.beRepaired(6);

    std::cout << "--- Guard Gate test ---" << std::endl;
    scav1.guardGate();
    scav2.guardGate();
    scav3.guardGate();

    return 0;
}
