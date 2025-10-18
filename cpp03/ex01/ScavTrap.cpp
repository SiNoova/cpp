#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "ScavTrap: default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string new_name) : ClapTrap(new_name)
{
	HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
	std::cout << "ScavTrap: Custom name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap: copy constructor called" << std::endl;
}


ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
	}
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (EnergyPoints && HitPoints)
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else if (!EnergyPoints)
		std::cout << "ScavTrap " << name << " has no energy points, it can't attack!" << std::endl;
	else
		std::cout << "ScavTrap " << name << " is dead, it can't attack!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode!" << std::endl;
}
