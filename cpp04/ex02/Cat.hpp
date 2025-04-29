#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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