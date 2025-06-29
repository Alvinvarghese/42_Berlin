# 	$< :: 
#		Refers to the current source file (e.g., megaphone.cpp).
#   $@ :: 
#	 Refers to the current target object file (e.g., megaphone.o).
#
#

NAME = megaphone
CC = c++
FLAG = -Wall -Werror -Wextra
STD = -std=c++98

SRC = megaphone.cpp
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

.PHONY: all clean fclean re