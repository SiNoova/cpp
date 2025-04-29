#include "Brain.hpp"

Brain::Brain()
{
	for(int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

void Brain::saveIdea(const std::string &idea)
{
    for (int i = 0; i < 100; i++)
    {
        if (ideas[i] == "")
        {
            ideas[i] = idea;
            break;
        }
    }
}

void Brain::printIdeas(void) const
{
    for(int i = 0; !ideas[i].empty() && i < 100; i++)
        std::cout << "Idea " << i << " :" << ideas[i] << '\n';
}