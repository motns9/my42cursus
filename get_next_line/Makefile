NAME = get_next_line.a

CC = cc
AR = ar rcs
RM = rm -f

SRCS = get_next_line.c \
       get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

BUFFER_SIZE ?= 42

CFLAGS = -Wall -Wextra -Werror -I. -D BUFFER_SIZE=$(BUFFER_SIZE)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all
