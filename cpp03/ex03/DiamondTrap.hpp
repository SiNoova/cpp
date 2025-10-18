#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string new_name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap& operator=(const DiamondTrap &other);
	~DiamondTrap();
	void attack(const std::string& target);
	void whoAmI();
};


#endif