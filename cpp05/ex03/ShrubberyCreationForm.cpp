#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target_name(target)
{	
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream out((target_name + "_shrubbery").c_str());
	if (!out.is_open())
		throw std::runtime_error("Failed to create file: " + target_name + "_shrubbery");
    out << "       _-_\n"
		<< "    /~~   ~~\\\n"
		<< " /~~         ~~\\\n"
		<< "{               }\n"
		<< " \\  _-     -_  /\n"
		<< "   ~  \\\\ //  ~\n"
		<< "_- -   | | _- _\n"
		<< "  _ -  | |   -_\n"
		<< "      // \\\\\n";

    out.close();
	std::cout << "a tree was created in " << target_name << "_shrubbery" << std::endl;
}
