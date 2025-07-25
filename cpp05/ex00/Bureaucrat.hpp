#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string init_name, int init_grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat &other);
	~Bureaucrat();
	const std::string& getName() const;
	const int getGrade() const;
	void IncrementGrade();
	void DecrementGrade();
	class GradeTooHighException : public std::exception
	{
		private:
			const std::string message;
		public:
			GradeTooHighException(const std::string new_message);
			const char *what() const throw();
			~GradeTooHighException() throw();
	};
	class GradeTooLowException : public std::exception
	{
		private:
			const std::string message;
		public:
			GradeTooLowException(const std::string new_message);
			const char *what() const throw();
			~GradeTooLowException() throw();
	};
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif