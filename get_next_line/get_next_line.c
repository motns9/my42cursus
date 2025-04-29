/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:13:08 by msbita            #+#    #+#             */
/*   Updated: 2025/04/29 19:13:09 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static long	ft_read_and_append(int fd, char *temp_read, char **buffer_ptr)
{
	long	bytes_read;
	char	*original_buffer;

	original_buffer = *buffer_ptr;
	bytes_read = read(fd, temp_read, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-1);
	if (bytes_read == 0)
		return (0);
	temp_read[bytes_read] = '\0';
	if (!original_buffer)
		*buffer_ptr = ft_strdup(temp_read);
	else
		*buffer_ptr = ft_strjoin(original_buffer, temp_read);
	if (!*buffer_ptr)
		return (-2);
	return (bytes_read);
}

static int	ft_process_buffer(char *buffer, char **line_out, char **remainder_out)
{
	size_t	i;
	char	*temp_line;
	char	*temp_remainder;

	*line_out = NULL;
	*remainder_out = NULL;
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	temp_line = ft_substr(buffer, 0, i);
	if (!temp_line)
		return (-1);
	temp_remainder = ft_substr(buffer, i, ft_strlen(buffer) - i);
	if (!temp_remainder)
	{
		free(temp_line);
		return (-1);
	}
	*line_out = temp_line;
	*remainder_out = temp_remainder;
	return (0);
}

char	*get_joined_buffer(char *buffer, int fd)
{
	char	temp[BUFFER_SIZE + 1];
	long	read_status;
	long	k;

	k = -1;
	while (++k <= BUFFER_SIZE)
		temp[k] = '\0';
	read_status = 1;
	while (read_status > 0 && !ft_strchr(temp, '\n'))
	{
		read_status = ft_read_and_append(fd, temp, &buffer);
		if (read_status == -1)
		{
			if (buffer)
				free(buffer);
			return (NULL);
		}
		if (read_status == -2)
			return (NULL);
	}
	if (read_status == 0 && !buffer)
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ret_line;
	char		*new_buffer_remainder;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = get_joined_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	if (ft_process_buffer(buffer, &ret_line, &new_buffer_remainder) == -1)
	{
		return (NULL);
	}
	free(buffer);
	buffer = new_buffer_remainder;
	return (ret_line);
}
