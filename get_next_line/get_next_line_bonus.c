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

#include "get_next_line_bonus.h"

static char	*read_buffer(int fd, char *saved)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && (!saved || !ft_strchr(saved, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			if (saved)
				free(saved);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!saved)
			saved = ft_strdup(buffer);
		else
			saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	return (saved);
}

static char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	return (line);
}

static char	*save_remainder(char *buffer)
{
	int		i;
	char	*remainder;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	remainder = ft_strdup(buffer + i);
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	saved[fd] = read_buffer(fd, saved[fd]);
	if (!saved[fd])
		return (NULL);
	line = extract_line(saved[fd]);
	saved[fd] = save_remainder(saved[fd]);
	return (line);
}
