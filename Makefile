NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I libt/libft
LIBFT_DIR = libt/libft

SRCS = push_swap.c validation.c utils.c
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
