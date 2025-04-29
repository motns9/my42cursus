NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

INC_DIR		= includes
SRC_DIR		= srcs

SRCS_FILES	= ft_putchar.c \
			  ft_putstr.c \
			  ft_strcmp.c \
			  ft_strlen.c \
			  ft_swap.c

SRCS		= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)

CFLAGS		+= -I$(INC_DIR)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

$(SRC_DIR)/%.o:	$(SRC_DIR)/%.c $(INC_DIR)/libft.h
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
