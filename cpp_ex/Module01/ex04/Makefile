NAME = SedIsForLosers
CC = c++
FLAG = -Wall -Werror -Wextra -g
STD = -std=c++98

SRC =main.cpp FileHandler.cpp
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
	clear

re: fclean all

run: re
	clear
	./$(NAME) testfile.txt hello HAHA

.PHONY: all clean fclean re