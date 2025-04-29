#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		Brain& operator=(const Brain &other);
		void saveIdea(const std::string &idea);
        void printIdeas(void) const;
		~Brain();
};

#endif