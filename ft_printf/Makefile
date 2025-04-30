NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
       ft_utils.c \
       ft_handle_chars.c \
       ft_handle_numbers.c \
       ft_handle_hex.c \
       ft_parse_flags.c

BONUS_SRCS = $(SRCS)

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus
