#include "HumanB.hpp"

void HumanB::attack()
{
	if (Weapon_name)
		std::cout << name << " attacks with their " << Weapon_name->getType() << std::endl;
	else
		std::cout << name << " has no weapons!" << std::endl;

}

HumanB::HumanB(std::string new_name)
{
	Weapon_name = NULL;
	name = new_name;
}

void HumanB::setWeapon(Weapon& new_w)
{
	Weapon_name = &new_w;
}
