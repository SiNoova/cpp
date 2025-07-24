# ifndef PRESIDNET_HPP
# define PRESIDNET_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string target_name;
		void executeAction() const;
	public:
		PresidentialPardonForm(const std::string target);
};

#endif