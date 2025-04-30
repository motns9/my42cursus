NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

SRCS_BONUS = ft_printf_bonus.c \
             ft_printf_parse_bonus.c \
             ft_printf_process_bonus.c \
             ft_printf_handlers_char_bonus.c \
             ft_printf_handlers_nbr_bonus.c \
             ft_printf_handlers_hexptr_bonus.c \
             ft_printf_nbr_utils_bonus.c \
             ft_printf_utils_bonus.c \
             ft_printf_prefix_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_BONUS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS_BONUS)

bonus: $(NAME)

%.o: %.c ft_printf_bonus.h $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
