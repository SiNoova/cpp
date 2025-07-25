#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :  AForm("RobotomyRequestForm", 72, 45), target_name(target)
{
	static int counter = 0;
	std::srand(std::time(NULL) + counter++);
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << ":: drilling noises :: " << target_name;
	if (std::rand() % 2)
		std::cout << " has been robotomized successfully" << std::endl;
	else
		std::cout << " has not been robotomized successfully" << std::endl;
}
