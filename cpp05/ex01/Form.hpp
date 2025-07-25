#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int min_grade_sign;
		const int min_grade_excute;
	public:
		Form();
		Form(const std::string init_name, const int min_g_sign, const int min_g_excute);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		const std::string& get_name() const;
		bool is_it_signed() const;
		int GetMinGradeToSign() const;
		int GetMinGradeToExcute() const;
		void beSigned(Bureaucrat &bureaucrat);
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

std::ostream& operator<<(std::ostream& out, const Form& b);

#endif