

NAME=pipex

CC= gcc

FLAGS= -Wall -Wextra -Werror

SRCS= main.c pipex_helper.c pipex_helper2.c pipex_helper3.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)
$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o pipex

clean:
	rm -rf $(OBJ)


fclean: clean
	rm -rf $(NAME)

re: fclean all
