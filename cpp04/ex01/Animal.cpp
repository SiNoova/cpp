#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
	type = other.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal Copy assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}


void Animal::makeSound() const
{
	std::cout << "generic animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::saveIdea(const std::string &idea)
{
    (void)idea;
    std::cout << "A general animal can't save an idea! It doesn't have a brain!" << std::endl;
}

void Animal::printIdeas(void) const
{
    std::cout << "A general aniaml can't print ideas! It doesn't have a brain!" << std::endl;
}
