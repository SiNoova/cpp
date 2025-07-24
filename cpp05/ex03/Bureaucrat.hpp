#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(std::string init_name, int init_grade);
	~Bureaucrat();
	const std::string& getName() const;
	const int& getGrade() const;
	void IncrementGrade();
	void DecrementGrade();
	void signForm(AForm &edited_form);
	void executeForm(AForm const & form) const;
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif