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
#
NAME = get_next_line.a
# Ou si vous préférez un exécutable de test pour la partie obligatoire:
# NAME = gnl_test

CC = cc
AR = ar rcs
RM = rm -f

# --- Sources & Objets Obligatoires ---
SRCS = get_next_line.c \
       get_next_line_utils.c
# Pour un exécutable de test obligatoire, ajoutez : main.c
# SRCS += main.c

OBJS = $(SRCS:.c=.o)

# --- Sources & Objets Bonus ---
BONUS_SRCS = get_next_line_bonus.c \
             get_next_line_utils_bonus.c
# Pour un exécutable de test bonus, ajoutez : main_bonus.c (ou le même main)
# BONUS_SRCS += main_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)


BUFFER_SIZE ?= 42
CFLAGS = -Wall -Wextra -Werror -I. -D BUFFER_SIZE=$(BUFFER_SIZE)
# Peut nécessiter -D_GNU_SOURCE pour OPEN_MAX sur certains systèmes linux
# CFLAGS += -D_GNU_SOURCE

.PHONY: all clean fclean re bonus

# Règle par défaut (Partie Obligatoire)
all: $(NAME)

# Règle pour créer la librairie obligatoire
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
# OU Règle pour créer l'exécutable de test obligatoire
# $(NAME): $(OBJS)
#	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


# Règle Bonus (Compile les fichiers _bonus)
# Crée une librairie bonus ou un exécutable bonus
# Par exemple, créons un exécutable de test bonus nommé gnl_bonus_test
bonus: $(BONUS_OBJS)
	@echo "Compiling Bonus..."
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o gnl_bonus_test # Nom de l'exécutable bonus
# OU pour une librairie bonus :
# bonus: $(BONUS_OBJS)
#	@echo "Creating Bonus Library..."
#	$(AR) get_next_line_bonus.a $(BONUS_OBJS)


# Règle générique de compilation .c -> .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) gnl_bonus_test get_next_line_bonus.a # Supprime tous les artefacts possibles

re: fclean all
#
