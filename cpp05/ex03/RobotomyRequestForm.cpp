#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target_name("Default") 
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :  AForm("RobotomyRequestForm", 72, 45), target_name(target)
{
	static int counter = 0;
	std::srand(std::time(NULL) + counter++);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm("RobotomyRequestForm", 72, 45), target_name(other.target_name)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    (void)other;
    return (*this);
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << ":: drilling noises :: " << target_name;
	if (std::rand() % 2)
		std::cout << " has been robotomized successfully" << std::endl;
	else
		std::cout << " has not been robotomized successfully" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
