#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat so3ad("so3ad", 15);
	Form aa("7nak", 15, 15);
	std::cout << so3ad;
	std::cout << aa;

	so3ad.signForm(aa);
	std::cout << aa;
}