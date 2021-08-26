CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRCS=do_op.c ft_atoi.c operation.c
RM=rm -f
OBJ=$(SRCS:.c=.o)
NAME=do-op

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
