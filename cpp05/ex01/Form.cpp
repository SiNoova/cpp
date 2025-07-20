#include "Form.hpp"

Form::Form(std::string init_name, int min_g_sign, int min_g_excute) 
: name(init_name), min_grade_sign(min_g_sign), min_grade_excute(min_g_sign) 
{
	if (min_grade_sign < 1 || min_grade_excute < 1)
		throw GradeTooHighException();
	else if (min_grade_sign > 150 || min_grade_excute > 150)
		throw GradeTooLowException();
}

const std::string& Form::get_name() const
{
	return name;
}

bool Form::is_it_signed() const
{
	return is_signed;
}

int Form::GetMinGradeToExcute() const
{
	return min_grade_excute;
}

int Form::GetMinGradeToSign() const
{
	return min_grade_sign;
}

std::ostream& operator<<(std::ostream& out, const Form& b)
{
	out << b.get_name() << ", Form's min grade to sign " << b.GetMinGradeToSign() << ", min grade to excute " << b.GetMinGradeToExcute();
	if (b.is_it_signed())
		std::cout << " and it's signed" << std::endl;
	else
		std::cout << " and it's not signed yet" << std::endl;
	return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "form error: grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form error: grade is too low";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	
}
