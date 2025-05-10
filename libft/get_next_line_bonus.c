/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:54:14 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 16:54:14 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char *p)
{
	free(p);
	return (NULL);
}

static char	*ft_extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_save_remainder(char *stash)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (ft_free(stash));
	if (stash[i] == '\n')
		i++;
	remainder = malloc(ft_strlen(stash) - i + 1);
	if (!remainder)
		return (ft_free(stash));
	j = 0;
	while (stash[i + j])
	{
		remainder[j] = stash[i + j];
		j++;
	}
	remainder[j] = '\0';
	free(stash);
	return (remainder);
}

static char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(stash));
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(stash, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (ft_free(stash));
		}
		buffer[read_bytes] = '\0';
		stash = gnl_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_read_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = ft_save_remainder(stash[fd]);
	return (line);
}
