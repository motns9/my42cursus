NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

INCLUDES = -I. -I$(LIBFT_DIR)

SRCS = ft_printf.c \
       ft_utils.c \
       ft_handle_char.c \
       ft_handle_nbr.c \
       ft_handle_hex.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_printf_bonus.c \
             ft_parse_format_bonus.c \
             ft_process_format_bonus.c \
             ft_handle_char_bonus.c \
             ft_handle_nbr_bonus.c \
             ft_handle_hex_bonus.c \
             ft_utils_bonus.c \
             ft_nbr_utils_bonus.c \
             ft_prefix_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS_BONUS) $(LIBFT_A)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJS_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus