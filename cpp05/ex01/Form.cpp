#include "Form.hpp"


Form::GradeTooHighException::GradeTooHighException(const std::string new_message) : message(new_message)
{}

Form::GradeTooLowException::GradeTooLowException(const std::string new_message) : message(new_message)
{}

const char *Form::GradeTooHighException::what() const throw()
{
	return message.c_str();
}

const char *Form::GradeTooLowException::what() const throw()
{
	return message.c_str();
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}


Form::Form() : name("Default"), is_signed(false), min_grade_sign(150), min_grade_excute(150)
{
}

Form::Form(const std::string init_name, const int min_g_sign, const int min_g_excute) 
: name(init_name), is_signed(false), min_grade_sign(min_g_sign), min_grade_excute(min_g_excute)
{
	if (min_grade_sign < 1 || min_grade_excute < 1)
		throw GradeTooHighException("Form min grade to excute or to sign is too high");
	else if (min_grade_sign > 150 || min_grade_excute > 150)
		throw GradeTooLowException("Form min grade to excute or to sign is too low");
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

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= min_grade_sign)
		is_signed = true;
	else
		throw GradeTooLowException("bureaucrat's grade is too low to be able to sign");
}

Form::~Form()
{}

std::ostream& operator<<(std::ostream& out, const Form& b)
{
	out << b.get_name() << ", Form's min grade to sign " << b.GetMinGradeToSign() << ", min grade to excute " << b.GetMinGradeToExcute();
	if (b.is_it_signed())
		out << " and it's signed";
	else
		out << " and it's not signed yet";
	return out;
}

