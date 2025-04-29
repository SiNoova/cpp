#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "woouf" << std::endl;
}