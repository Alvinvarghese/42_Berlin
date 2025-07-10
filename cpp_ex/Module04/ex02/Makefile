NAME = poly
CC = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Brain.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
		$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	clear

re: fclean all

run: re
	clear
	./$(NAME)

.PHONY: all clean fclean re