#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : target_name(target), AForm("PresidentialPardonForm", 25, 5)
{}

void PresidentialPardonForm::executeAction() const
{
	std::cout << target_name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}