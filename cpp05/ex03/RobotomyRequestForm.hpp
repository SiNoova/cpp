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
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
};


#endif