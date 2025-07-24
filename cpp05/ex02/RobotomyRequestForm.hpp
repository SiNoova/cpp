#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <cstdlib>


class RobotomyRequestForm : public AForm
{
	private:
		const std::string target_name;
		void executeAction() const;
	public:
		RobotomyRequestForm(const std::string target);
};


#endif