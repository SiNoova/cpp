#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <stdexcept>

class ShrubberyCreationForm : public AForm 
{
	private:
		const std::string target_name;
		void executeAction() const;
	public :
		ShrubberyCreationForm(const std::string target);
};

#endif