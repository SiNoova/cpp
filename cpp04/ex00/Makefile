NAME = animal
SRC = main.cpp Dog.cpp Cat.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp
OBJ = $(SRC:%.cpp=%.o)
INCLUDE = Dog.hpp Cat.hpp Animal.hpp WrongAnimal.hpp WrongCat.hpp

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "Executable linked successfully!"

%.o: %.cpp $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	@rm -f $(OBJ)
	@echo "Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned executables"

re: fclean all