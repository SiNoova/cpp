NAME = replace
SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "Executable linked successfully!"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $<"

clean:
	@rm -f $(OBJ)
	@echo "Cleaned object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned executables"

re: fclean all
