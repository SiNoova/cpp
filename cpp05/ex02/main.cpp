#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
    {
        Bureaucrat Nova("Nova", 1);
        PresidentialPardonForm ppf("ppf");
        Nova.signForm(ppf);
        Nova.executeForm(ppf);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
	try
    {
        Bureaucrat Nova("Nova", 1);
        RobotomyRequestForm lol("xd");
        Nova.signForm(lol);
        Nova.executeForm(lol);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
	try
    {
        Bureaucrat Nova("Nova", 137);
        ShrubberyCreationForm scf("xddd");
        Nova.signForm(scf);
        Nova.executeForm(scf);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
}