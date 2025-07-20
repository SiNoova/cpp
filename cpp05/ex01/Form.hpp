#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		int min_grade_sign;
		int min_grade_excute;
	public:
		Form(std::string init_name, int min_g_sign, int min_g_excute);
		~Form();
		const std::string& get_name() const;
		bool is_it_signed() const;
		int GetMinGradeToSign() const;
		int GetMinGradeToExcute() const;
		void beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const Form& b);

#endif