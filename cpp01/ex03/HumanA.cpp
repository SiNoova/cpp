#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << name << " attacks with their " << Weapon_name.getType() << std::endl;
}

HumanA::HumanA(std::string new_name, Weapon& new_weapon) : name(new_name), Weapon_name(new_weapon)
{
}