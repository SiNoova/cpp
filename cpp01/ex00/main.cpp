#include "Zombie.hpp"

int main()
{
	Zombie test("zombie");
	test.announce();

	randomChump("alae");

	Zombie *zombie_p = newZombie("aymane");
	zombie_p->announce();

	delete zombie_p;
}