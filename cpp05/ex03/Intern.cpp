#include "Intern.hpp"

AForm* makeShrubberyCreationForm(const std::string target)
{
	return(new ShrubberyCreationForm(target));
}

AForm* makeRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* makePresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string form_name, const std::string target)
{
	std::string list_forms[3] = { "robotomy request", "presidential Pardon", "shrubbery creation"};
	AForm* (*functions[4])(const std::string) = {&makePresidentialPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == list_forms[i])
		{
			std::cout << "Intern creates " << form_name << "." << std::endl;
			return (functions[i](target));
		}
		std::cout << "Error creating the Form" << std::endl;
		return (NULL);
	}
}
