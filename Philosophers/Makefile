# Name of the final executable
NAME = philo

# C compiler
CC = cc

# Compiler flags
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror -pthread -O2

# Command to remove files and directories
RM = rm -rf

# List of header file dependencies
DEPENDENCIES = philo.h

# List of source files
SRCS = philo.c \
	arg_check.c \
	philo_info.c \
	philo_intialize.c \
	thread.c \
	fork.c \
	routine.c \
	eat.c \
	acquire_fork.c \
	sleep_think.c \
	die.c \
	display_mssg.c \
	utils.c \
	cleanup_resources.c

# List of object files, derived from source files by replacing .c with .o
OBJS = $(SRCS:.c=.o)

# Pattern rule to compile .c files into .o files
# $< is the first prerequisite (the .c file)
# $@ is the target (the .o file)
%.o: %.c $(DEPENDENCIES)
	$(CC) $(CFLAGS) -c $< -o $@

# Default target: build the final executable
all : $(NAME)

# Link object files to create the final executable
# $^ is the list of all prerequisites (the .o files)
# $@ is the target (the final executable)
$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean target: remove all object files
clean :
	$(RM) $(OBJS)

# Full clean target: remove all object files and the final executable
fclean : clean
	$(RM) $(NAME)

# Rebuild target: perform a full clean, then build everything again
re : fclean all

# Declare these targets as phony to avoid conflicts with files of the same name
.PHONY : all clean fclean re

############################################################################################

#NAME = philo

#CC = cc
#CFLAGS = -Wall -Wextra -Werror

#RM = rm -rf

#DEPENDENCIES = philo.h

#SRCS = philo.c \
#		arg_check.c 

#OBJS = $(SRCS:.c=.o)

#%.o: %.c $(DEPENDENCIES)
#	$(CC) $(CFLAGS) -c $< -o $@

#all : $(NAME)

#$(NAME) : $(OBJS)
#	$(CC) $(CFLAGS) $^ -o $@

#clean :
#	$(RM) $(OBJS)

#fclean : clean
#	$(RM) $(NAME)

#re : fclean all

#.PHONY : all clean fclean re
####################################################################################
