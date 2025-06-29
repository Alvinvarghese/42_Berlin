NAME = zombie
CC = c++
FLAG = -Wall -Werror -Wextra -g
STD = -std=c++98

SRC =main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAG) $(STD) -o $(NAME) $(OBJ)

%.o: %.cpp
		$(CC) $(FLAG) $(STD) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	clear
	./$(NAME)

.PHONY: all clean fclean re