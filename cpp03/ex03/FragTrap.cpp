#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap: default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string new_name) : ClapTrap(new_name)
{
	HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
	std::cout << "FragTrap: Custom name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	name = other.name;
	HitPoints = other.HitPoints;
	EnergyPoints = other.EnergyPoints;
	AttackDamage = other.AttackDamage;
	std::cout << "FragTrap: copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
	}
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}