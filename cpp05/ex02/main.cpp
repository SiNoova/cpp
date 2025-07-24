#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat alae("alae", 50);
		// Bureaucrat tani("alaeaa", 138);
		ShrubberyCreationForm btata("khobza");
		RobotomyRequestForm btata2("khobza2");
		PresidentialPardonForm btata3("khobza3");

		alae.signForm(btata);
		alae.signForm(btata2);
		alae.signForm(btata3);

		alae.executeForm(btata);
		alae.executeForm(btata2);
		alae.executeForm(btata3);
	}
	catch (std::exception &e)
	{
		std::cout << "Error " << e.what();
	}
}