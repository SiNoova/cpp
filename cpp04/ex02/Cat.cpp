#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
	idea = new Brain();
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	idea = new Brain(*other.idea);
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete idea;
		idea = new Brain(*other.idea);
	}
	return *this;
}


Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete idea;
}

void Cat::makeSound() const
{
	std::cout << "meoooow" << std::endl;
}

void Cat::saveIdea(const std::string &new_idea)
{
    idea->saveIdea(new_idea);
}

void Cat::printIdeas(void) const
{
    idea->printIdeas();
}