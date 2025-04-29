/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:13:21 by msbita            #+#    #+#             */
/*   Updated: 2025/04/29 19:13:21 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// La SEULE variable statique autorisée pour le bonus multi-FD
// Tableau pour stocker le buffer restant pour chaque FD.
// Les index du tableau ne correspondent PAS directement aux FDs.
// On cherche une entrée libre ou celle correspondant au bon FD.
// Initialisé à zéro par défaut pour les variables statiques.
static char	*fd_buffers[OPEN_MAX];

// --- Fonctions d'aide STATIQUES spécifiques au bonus ---

// Libère la mémoire pour un FD donné et met son pointeur à NULL
static void	clear_buffer(int fd)
{
	if (fd >= 0 && fd < OPEN_MAX && fd_buffers[fd])
	{
		free(fd_buffers[fd]);
		fd_buffers[fd] = NULL;
	}
}

// Lit depuis le FD et ajoute au buffer existant pour ce FD
// Renvoie: 1 (lecture ok), 0 (EOF), -1 (erreur read), -2 (erreur malloc)
static int	read_to_buffer(int fd, char **buffer)
{
	char	read_temp[BUFFER_SIZE + 1];
	long	bytes_read;
	char	*temp_join;

	bytes_read = read(fd, read_temp, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	if (bytes_read == 0)
		return (0);
	read_temp[bytes_read] = '\0';
	if (!*buffer)
		*buffer = ft_strdup(read_temp);
	else
	{
		temp_join = ft_strjoin(*buffer, read_temp);
		// ft_strjoin libère l'ancien *buffer si succès
		*buffer = temp_join;
	}
	if (!*buffer)
		return (-2); // Malloc a échoué
	return (1);
}

// Extrait la ligne et met à jour le buffer avec le reste
// Renvoie la ligne allouée, ou NULL si erreur malloc
static char	*extract_line_and_update_buffer(int fd)
{
	char	*line;
	char	*remainder;
	char	*current_buffer;
	size_t	i;

	current_buffer = fd_buffers[fd];
	i = 0;
	while (current_buffer[i] != '\n' && current_buffer[i] != '\0')
		i++;
	if (current_buffer[i] == '\n')
		i++;
	line = ft_substr(current_buffer, 0, i);
	if (!line)
		return (NULL); // Erreur malloc ligne
	remainder = ft_substr(current_buffer, i, ft_strlen(current_buffer) - i);
	free(current_buffer); // Libère l'ancien buffer complet
	fd_buffers[fd] = remainder; // Met à jour avec le reste
	if (!remainder) // Erreur malloc reste
	{
		free(line); // Nettoie la ligne qu'on ne peut pas retourner
		return (NULL);
	}
	return (line);
}

// --- Fonction Principale Bonus ---
char	*get_next_line_bonus(int fd)
{
	char	*line_result;
	int		read_status;

	// Vérifications initiales
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	// Si le buffer pour ce FD ne contient pas déjà une ligne complète
	if (!fd_buffers[fd] || !ft_strchr(fd_buffers[fd], '\n'))
	{
		read_status = 1;
		while (read_status == 1) // Lire jusqu'à \n, EOF ou erreur
		{
			read_status = read_to_buffer(fd, &fd_buffers[fd]);
			if (read_status <= 0) // EOF ou Erreur
				break;
			if (ft_strchr(fd_buffers[fd], '\n')) // Ligne trouvée
				break;
		}
		if (read_status == -1 || read_status == -2) // Erreur read ou malloc
		{
			clear_buffer(fd);
			return (NULL);
		}
	}
	// Si après lecture, le buffer est vide ou NULL (EOF atteinte avant, ou erreur)
	if (!fd_buffers[fd] || fd_buffers[fd][0] == '\0')
	{
		clear_buffer(fd);
		return (NULL);
	}
	// Extraire la ligne et mettre à jour le buffer avec le reste
	line_result = extract_line_and_update_buffer(fd);
	if (!line_result) // Erreur malloc dans l'extraction
	{
		clear_buffer(fd); // Nettoyer le buffer potentiellement corrompu
		return (NULL);
	}
	// Si le reste est vide après extraction, nettoyer aussi
	if (fd_buffers[fd] && fd_buffers[fd][0] == '\0')
		clear_buffer(fd);
	return (line_result);
}