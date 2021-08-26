CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=main.c
RM=rm -f
OBJ=$(SRCS:.c=.o)
NAME=ft_cat

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

.PHONY : all clean fclean
