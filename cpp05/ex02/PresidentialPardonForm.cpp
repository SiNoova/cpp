#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target_name("Default") 
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :  AForm("PresidentialPardonForm", 25, 5), target_name(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PresidentialPardonForm", 25, 5), target_name(other.target_name)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    (void)other;
    return (*this);
}


void PresidentialPardonForm::executeAction() const
{
	std::cout << target_name << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}