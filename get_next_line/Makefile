NAME = get_next_line.a

CC = cc
AR = ar rcs
RM = rm -f

SRCS = get_next_line.c \
       get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = get_next_line_bonus.c \
             get_next_line_utils_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: fclean $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
