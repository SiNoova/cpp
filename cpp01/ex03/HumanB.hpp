#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *Weapon_name;
		std::string name;
	public:
		void attack(); 
		HumanB(std::string new_name);
		void setWeapon(Weapon& new_w);
};

#endif