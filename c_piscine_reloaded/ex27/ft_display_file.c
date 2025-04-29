/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:06:39 by msbita            #+#    #+#             */
/*   Updated: 2025/04/26 15:12:14 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

void	ft_putstr_fd(char *str, int fd)
{
	int	len;

	if (!str)
		return ;
	len = 0;
	while (str[len])
		len++;
	if (len > 0)
		write(fd, str, len);
}

static int	read_and_write_content(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	ssize_t	write_result;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (1);
		if (bytes_read == 0)
			break ;
		write_result = write(1, buffer, bytes_read);
		if (write_result < 0 || write_result != bytes_read)
			return (1);
	}
	return (0);
}

static int	process_single_file(char *filepath)
{
	int	fd;
	int	read_write_status;
	int	close_status;
	int	final_status;

	final_status = 0;
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		return (1);
	}
	read_write_status = read_and_write_content(fd);
	close_status = close(fd);
	if (read_write_status != 0)
	{
		ft_putstr_fd("Cannot read file.\n", 2);
		final_status = 1;
	}
	if (close_status == -1)
	{
		final_status = 1;
	}
	return (final_status);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (1);
	}
	else if (argc > 2)
	{
		ft_putstr_fd("Too many arguments.\n", 2);
		return (1);
	}
	else
	{
		return (process_single_file(argv[1]));
	}
}
