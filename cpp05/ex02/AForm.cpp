#include "AForm.hpp"

AForm::AForm(const std::string init_name, int min_g_sign, int min_g_excute) 
: name(init_name), is_signed(false), min_grade_sign(min_g_sign), min_grade_excute(min_g_excute)
{
	if (min_grade_sign < 1 || min_grade_excute < 1)
		throw GradeTooHighException();
	else if (min_grade_sign > 150 || min_grade_excute > 150)
		throw GradeTooLowException();
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

// AForm::~AForm()
// {
	
// }
std::ostream& operator<<(std::ostream& out, const AForm& b)
{
	out << b.get_name() << ", AForm's min grade to sign " << b.GetMinGradeToSign() << ", min grade to excute " << b.GetMinGradeToExcute();
	if (b.is_it_signed())
		out << " and it's signed" << std::endl;
	else
		out << " and it's not signed yet" << std::endl;
	return out;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

const char *AForm::FormNotSigned::what() const throw()
{
	return "Form is not signed";
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= min_grade_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!is_it_signed())
		throw FormNotSigned();
	if (executor.getGrade() > GetMinGradeToExcute())
		throw GradeTooLowException();

	executeAction();
}