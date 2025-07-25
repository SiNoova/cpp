#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(const std::string new_message) : message(new_message)
{}

AForm::GradeTooLowException::GradeTooLowException(const std::string new_message) : message(new_message)
{}

AForm::FormNotSigned::FormNotSigned(const std::string new_message) : message(new_message)
{}

const char *AForm::GradeTooHighException::what() const throw()
{
	return message.c_str();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return message.c_str();
}

const char *AForm::FormNotSigned::what() const throw()
{
	return message.c_str();
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::FormNotSigned::~FormNotSigned() throw() {}


AForm::AForm() : name("Default"), is_signed(false), min_grade_sign(150), min_grade_excute(150)
{
}

AForm::AForm(const std::string init_name, int min_g_sign, int min_g_excute) 
: name(init_name), is_signed(false), min_grade_sign(min_g_sign), min_grade_excute(min_g_excute)
{
	if (min_grade_sign < 1 || min_grade_excute < 1)
		throw GradeTooHighException("Form min grade to excute or to sign is too high");
	else if (min_grade_sign > 150 || min_grade_excute > 150)
		throw GradeTooLowException("Form min grade to excute or to sign is too low");
}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed),
	 min_grade_sign(other.min_grade_sign), min_grade_excute(other.min_grade_excute)
{
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		is_signed = other.is_signed;
	}
	return (*this);
}

const std::string& AForm::get_name() const
{
	return name;
}

bool AForm::is_it_signed() const
{
	return is_signed;
}

int AForm::GetMinGradeToExcute() const
{
	return min_grade_excute;
}

int AForm::GetMinGradeToSign() const
{
	return min_grade_sign;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= min_grade_sign)
		is_signed = true;
	else
		throw GradeTooLowException(bureaucrat.getName() + " has too low grade to sign " + get_name());
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!is_it_signed())
		throw FormNotSigned("the form is not signed yet");
	if (executor.getGrade() > GetMinGradeToExcute())
		throw GradeTooLowException(executor.getName() + " has too low grade to excute " + get_name());

	executeAction();
}

AForm::~AForm()
{}

std::ostream& operator<<(std::ostream &out, const AForm& b)
{
	out << b.get_name() << ", AForm's min grade to sign " << b.GetMinGradeToSign() << ", min grade to excute " << b.GetMinGradeToExcute();
	if (b.is_it_signed())
		out << " and it's signed";
	else
		out << " and it's not signed yet";
	return out;
}
