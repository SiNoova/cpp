#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string init_name, int init_grade)
	: name(init_name), grade(init_grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const std::string& Bureaucrat::getName() const
{
	return name;
}

const int& Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::IncrementGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::DecrementGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

Bureaucrat::~Bureaucrat()
{}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}

