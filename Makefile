CC = cc

CFLAGS = -Wall -Wextra -Werror -I.

NAME = push_swap

SRC = lists_utils.c \
      parsing.c \
      push_swap.c \
      free_utils.c \
      push_swap_utils.c \
      push_swap_utils2.c \
      ops/push_a.c\
      ops/push_b.c \
      ops/reverse_rotate_a.c \
      ops/rotate_a.c \
      ops/swap_a.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ)  $(LIB) -o $(NAME)

$(LIB):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make fclean -C ./libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
