CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=main.c ft_split.c ft_strjoin.c ft_list.c ft_strdup.c ft_strcmp.c
RM=rm -f
OBJ=$(SRCS:.c=.o)
NAME=rush-02

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean
