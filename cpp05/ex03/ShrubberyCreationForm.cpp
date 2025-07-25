#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target_name("Default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), target_name(target)
{	}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137), target_name(other.target_name)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    (void)other;
    return (*this);
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
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
