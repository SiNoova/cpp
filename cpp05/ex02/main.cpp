#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
    {
        Bureaucrat ruined("ruined", 1);
        PresidentialPardonForm ppf("ppf");
        ruined.signForm(ppf);
        ruined.executeForm(ppf);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	try
    {
        Bureaucrat ruined("ruined", 1);
        RobotomyRequestForm lol("xd");
        ruined.signForm(lol);
        ruined.executeForm(lol);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	try
    {
        Bureaucrat ruined("ruined", 137);
        ShrubberyCreationForm scf("xddd");
        ruined.signForm(scf);
        scf.execute(ruined);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}