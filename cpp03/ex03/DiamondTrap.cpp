#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap(), ScavTrap(), FragTrap(), name("Default")
{
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage; 
    std::cout << "DiamondTrap: default constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string new_name)
: ClapTrap(new_name + "_clap_name"), ScavTrap(new_name), FragTrap(new_name), name(new_name)
{
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage; 
    std::cout << "DiamondTrap: Custom name constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
: ClapTrap(other.name + "_clap_name"), ScavTrap(other.name), FragTrap(other.name), name(other.name)
{
    std::cout << "DiamondTrap: copy constructor called" << std::endl;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
	ClapTrap::operator=(other);
    name = other.name;
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << name << " and ClapTrap name is " << ClapTrap::name << std::endl;
}
