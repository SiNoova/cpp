#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
	idea = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	idea = new Brain(*other.idea);
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete idea;
		idea = new Brain(*other.idea);
	}
	return *this;
}


Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete idea;
}

void Dog::makeSound() const
{
	std::cout << "woouf" << std::endl;
}

void Dog::saveIdea(const std::string &new_idea)
{
    idea->saveIdea(new_idea);
}

void Dog::printIdeas(void) const
{
    idea->printIdeas();
}