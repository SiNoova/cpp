#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name ("Default"), grade(150)
{}

Bureaucrat::Bureaucrat(std::string init_name, int init_grade)
	: name(init_name), grade(init_grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

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
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::DecrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form &edited_form)
{
	try
	{
		edited_form.beSigned(*this);
		std::cout << name << " signed " << edited_form.get_name();
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn’t sign " << edited_form.get_name() << " because " << e.what();
	}
}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}

