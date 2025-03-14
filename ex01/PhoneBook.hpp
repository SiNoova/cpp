#ifndef CLASS_H
# define CLASS_H

#include <iostream>
#include <cstdlib>
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
	public:
		void 	search();
		void 	add(int i);
		void	fexit();
	private:
		Contact contacts[8];
		int		size;
};



#endif