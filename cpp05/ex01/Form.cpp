#include "Form.hpp"

Form::Form() : name("Default"), is_signed(false), min_grade_sign(150), min_grade_excute(150)
{
}

Form::Form(const std::string init_name, const int min_g_sign, const int min_g_excute) 
: name(init_name), is_signed(false), min_grade_sign(min_g_sign), min_grade_excute(min_g_excute)
{
	if (min_grade_sign < 1 || min_grade_excute < 1)
		throw GradeTooHighException();
	else if (min_grade_sign > 150 || min_grade_excute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name), is_signed(other.is_signed),
	 min_grade_sign(other.min_grade_sign), min_grade_excute(other.min_grade_excute)
{
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		is_signed = other.is_signed;
	}
	return (*this);
}

Form::~Form()
{
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
		out << " and it's signed";
	else
		out << " and it's not signed yet";
	return out;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= min_grade_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}
