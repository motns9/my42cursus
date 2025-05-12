NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
       parsing.c \
       stack_operations.c \
       stack_operations2.c \
       stack_operations3.c \
       sort_small.c \
       sort_big.c \
       utils.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
