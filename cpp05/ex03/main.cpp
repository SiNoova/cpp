#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	AForm *invalid = NULL;
    try
    {
        Bureaucrat ygor("ygor", 1);
        Intern nova;
        invalid = nova.makeForm("invalid", "thaNoobest");
        ygor.signForm(*invalid);
        ygor.executeForm(*invalid);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    delete invalid;
	AForm *ppf = NULL;
    try
    {
        Bureaucrat ygor("ygor", 1);
        Intern nova;
        ppf = nova.makeForm("presidential pardon", "thaBest");
        ygor.signForm(*ppf);
        ygor.executeForm(*ppf);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    delete ppf;
    AForm *rrf = NULL;
    try
    {
        Bureaucrat ygor("ygor", 1);
        Intern nova;
        rrf = nova.makeForm("robotomy request", "thaGreatest");
        ygor.signForm(*rrf);
        ygor.executeForm(*rrf);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    delete rrf;
	AForm *scf = NULL;
    try
    {
        Bureaucrat ygor("ygor", 137);
        Intern nova;
        scf = nova.makeForm("shrubbery creation", "theSweetest");
        ygor.signForm(*scf);
        ygor.executeForm(*scf);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    delete scf;
}