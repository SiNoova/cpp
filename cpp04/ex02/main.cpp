#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    AAnimal *cat = new Dog();
    AAnimal *dog = new Cat();

	cat->makeSound();
	dog->makeSound();

	cat->saveIdea("Loaf");
	dog->saveIdea("running");

	cat->printIdeas();
	dog->printIdeas();

	delete cat;
	delete dog;
}