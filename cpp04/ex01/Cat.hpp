#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *idea;
	public:
		Cat();
		Cat(const Cat &other);
		Cat& operator=(const Cat &other);
		~Cat();
		void makeSound() const;
		void saveIdea(const std::string &idea);
        void printIdeas(void) const;

};

#endif