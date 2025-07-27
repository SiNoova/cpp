#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat Nova("Nova", 112);

    try
	{
        Form nForm("test", 160, 11);
        std::cout << nForm << '\n';
        Nova.signForm(nForm);
        std::cout << nForm << '\n';
    }
	catch (const std::exception& e)
	{
        std::cout << e.what() << '\n';
    }

	std::cout << "---------------------\n";
    
	try
	{
        Form nForm("test2", 130, 11);
        std::cout << nForm << '\n';
        Nova.signForm(nForm);
        std::cout << nForm << '\n';
    }
	catch (const std::exception& e)
	{
        std::cout << e.what() << '\n';
    }

    std::cout << "---------------------\n";

    try
	{
        Form nForm("test2", 15, 5);
        std::cout << nForm << '\n';
        Nova.signForm(nForm);
        std::cout << nForm << '\n';
    }
	catch (const std::exception& e)
	{
        std::cout << e.what() << '\n';
    }

    return 0;
}