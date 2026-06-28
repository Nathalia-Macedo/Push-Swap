NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I libft
LIBFT_DIR = libft

SRCS = main.c validation.c utils.c sort_small.c \
       commands/push.c commands/rotate.c commands/rotate_reverse.c commands/swap.c \
       initialization_stack/initialization_t_stack.c \
       operations/push.c operations/rotate.c operations/rev_rotate.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
