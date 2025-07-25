#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :  AForm("PresidentialPardonForm", 25, 5), target_name(target)
{}

void PresidentialPardonForm::executeAction() const
{
	std::cout << target_name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}