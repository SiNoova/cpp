# ifndef PRESIDNET_HPP
# define PRESIDNET_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private: 
		const std::string target_name;
		void executeAction() const;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
};

#endif