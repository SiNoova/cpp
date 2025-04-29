#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* Wronga = new WrongAnimal();
	const WrongAnimal* Wrongc = new WrongCat();
	const WrongCat* tstc = new WrongCat();
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << Wronga->getType() << " " << std::endl;
	std::cout << Wrongc->getType() << " " << std::endl;
	std::cout << tstc->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	Wronga->makeSound();
	Wrongc->makeSound();
	tstc->makeSound();
	delete meta;
	delete j;
	delete i;
	delete Wronga;
	delete Wrongc;
	delete tstc;
	return 0;
}