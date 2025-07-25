#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat so3ad("so3ad", 15);
	Form aa("7nak", 15, 15);
	std::cout << so3ad << std::endl;
	std::cout << aa << std::endl;

	so3ad.signForm(aa);
	std::cout << aa << std::endl;
}