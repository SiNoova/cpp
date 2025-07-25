#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern &operator=(const Intern& other);
		~Intern();
		AForm* makeForm(const std::string form_name, const std::string target);
		class CreationErrorException : public std::exception
		{
			const char *what() const throw();
		};
};

#endif