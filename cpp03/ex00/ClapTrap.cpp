#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string new_name) : name(new_name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "Custom name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	name = other.name;
	HitPoints = other.HitPoints;
	EnergyPoints = other.EnergyPoints;
	AttackDamage = other.AttackDamage;
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (EnergyPoints && HitPoints)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else if (!EnergyPoints)
		std::cout << "ClapTrap " << name << " has no energy points, it can't attack!" << std::endl;
	else
		std::cout << "ClapTrap " << name << " is dead, it can't attack!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (EnergyPoints && HitPoints)
	{
		HitPoints += amount;
		std::cout << "ClapTrap " << name << " repaired " << amount << " points, and now has " << HitPoints << " of health!" << std::endl;
		EnergyPoints--;
	}
	else if (!EnergyPoints)
		std::cout << "ClapTrap " << name << " has no energy points, it can't be repaired!" << std::endl;
	else
		std::cout << "ClapTrap " << name << " is dead, it can't be repaired!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!HitPoints)
		std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << name << " took " << amount << " points of damage";
		if (amount >= HitPoints)
		{
			std::cout << ", and now has 0 health. It died!" << std::endl;
			HitPoints = 0;
		}
		else
		{
			std::cout << ", and still has " << HitPoints - amount << " of health!" << std::endl;
			HitPoints -= amount;
		}
	}
}