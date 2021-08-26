SRCS = main.c split.c parse_file.c check_map.c change_map.c free.c string.c dp.c parse_stdin.c
OBJ = ${SRCS:.c=.o}
NAME = bsq

SRC_DIR = srcs
OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJ))

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	$(CC) $^ -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/header.h
	$(CC) $(CFLAGS)  -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
