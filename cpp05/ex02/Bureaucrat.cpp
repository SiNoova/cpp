#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string init_name, int init_grade)
	: name(init_name), grade(init_grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
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
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::DecrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm &edited_form)
{
	try
	{
		edited_form.beSigned(*this);
		std::cout << name << " signed " << edited_form.get_name() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn’t sign " << edited_form.get_name() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{}

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
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.get_name() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " can't execute " << form.get_name() << " because of " << e.what() << std::endl;
	}
}
