#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Limite possible pour le nombre de FDs gérés simultanément.
// Utiliser OPEN_MAX est idéal mais peut être non portable ou nécessiter des flags.
// Une valeur fixe comme 1024 est une alternative sûre.
# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

// Pas de définition de structure ici si on utilise une variable statique
// entièrement gérée dans le .c

// --- Prototypes des fonctions Utilitaires Bonus ---
// (Ce sont les mêmes que pour la partie obligatoire)
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);

// --- Prototype de la fonction GNL Bonus ---
char	*get_next_line_bonus(int fd);

#endif