#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string new_message) : message(new_message)
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string new_message) : message(new_message)
{}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return message.c_str();
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return message.c_str();
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}



Bureaucrat::Bureaucrat() : name ("Default"), grade(150)
{}

Bureaucrat::Bureaucrat(std::string init_name, int init_grade)
	: name(init_name), grade(init_grade)
{
	if (grade < 1)
		throw GradeTooHighException("Bureaucrat grade it too high");
	else if (grade > 150)
		throw GradeTooLowException("Bureaucrat grade it too Low");
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

const std::string& Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::IncrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException("Bureaucrat grade it too high");
	grade--;
}

void Bureaucrat::DecrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException("Bureaucrat grade it too low");
	grade++;
}

void Bureaucrat::signForm(Form &edited_form)
{
	try
	{
		edited_form.beSigned(*this);
		std::cout << name << " signed " << edited_form.get_name() << " successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn’t sign " << edited_form.get_name() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat()
{}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
