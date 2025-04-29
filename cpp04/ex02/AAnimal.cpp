#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	type = "AAnimal";
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	type = other.type;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor called" << std::endl;
}


void AAnimal::makeSound() const
{
	std::cout << "generic AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}

void AAnimal::saveIdea(const std::string &idea)
{
    (void)idea;
    std::cout << "A general AAnimal can't save an idea! It doesn't have a brain!" << std::endl;
}

void AAnimal::printIdeas(void) const
{
    std::cout << "A general aniaml can't print ideas! It doesn't have a brain!" << std::endl;
}
