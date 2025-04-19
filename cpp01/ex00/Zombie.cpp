#include "Zombie.hpp"

Zombie::Zombie(std::string new_name) : name(new_name) {}

Zombie::~Zombie()
{
	std::cout << name << ": is destoryed" << std::endl;
}
void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
