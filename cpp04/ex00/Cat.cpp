#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "meoooow" << std::endl;
}