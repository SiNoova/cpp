#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 4;
    Animal* animals[size];

    std::cout << "\n--- Creating Animals ---\n";
    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Testing makeSound and ideas ---\n";
    animals[0]->makeSound(); 
    animals[1]->makeSound();
    animals[2]->makeSound();
    animals[3]->makeSound();

    animals[0]->saveIdea("Protect the house.");
    animals[2]->saveIdea("Nap in the sun.");
    animals[2]->saveIdea("Chase a laser pointer.");

    std::cout << "\n--- Printing ideas ---\n";
    animals[0]->printIdeas();
	std::cout << std::endl;
    animals[2]->printIdeas();

    std::cout << "\n--- Testing deep copy of a Cat ---\n";
    Cat originalCat;
    originalCat.saveIdea("Original cat idea.");
    Cat copiedCat = originalCat;

    std::cout << "\nOriginal Cat Ideas:\n";
    originalCat.printIdeas();

    std::cout << "\nCopied Cat Ideas:\n";
    copiedCat.printIdeas();

    originalCat.saveIdea("New idea in original cat.");
    std::cout << "\nAfter modifying original Cat:\n";
    std::cout << "Original Cat Ideas:\n";
    originalCat.printIdeas();
    std::cout << "Copied Cat Ideas (should not change):\n";
    copiedCat.printIdeas();

    std::cout << "\n--- Deleting Animals ---\n";
    for (int i = 0; i < size; ++i)
        delete animals[i];

    return 0;
}