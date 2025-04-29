#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &other);
		Animal& operator=(const Animal &other);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
		virtual void saveIdea(const std::string &idea);
        virtual void printIdeas(void) const;
};

#endif