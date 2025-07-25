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
		const int min_grade_sign;
		const int min_grade_excute;
	protected:
		virtual void executeAction() const = 0;
	public:
		AForm();
		AForm(const std::string init_name, const int min_g_sign, const int min_g_excute);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();
		const std::string& get_name() const;
		bool is_it_signed() const;
		int GetMinGradeToSign() const;
		int GetMinGradeToExcute() const;
		void beSigned(Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
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
		class FormNotSigned : public std::exception
		{
			private:
				const std::string message;
			public:
				FormNotSigned(const std::string new_message);
				const char *what() const throw();
				~FormNotSigned() throw();
		};

};

std::ostream& operator<<(std::ostream& out, const AForm& b);

#endif