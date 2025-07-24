#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		int min_grade_sign;
		int min_grade_excute;
	protected:
		virtual void executeAction() const = 0;
	public:
		AForm(const std::string init_name, int min_g_sign, int min_g_excute);
		const std::string& get_name() const;
		bool is_it_signed() const;
		int GetMinGradeToSign() const;
		int GetMinGradeToExcute() const;
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		class GradeTooHighException : public std::exception
		{
			const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char *what() const throw();
		};
		class FormNotSigned : public std::exception
		{
			const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const AForm& b);

#endif