/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:01:08 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:01:09 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_write_and_count(const char **format, int *len)
{
	if (*len == -1)
		return (-1);
	if (write(1, *format, 1) < 0)
	{
		*len = -1;
		return (-1);
	}
	(*len)++;
	(*format)++;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format)
		return (-1);
	len = 0;
	va_start(args, format);
	while (*format && len != -1)
	{
		if (*format == '%')
			ft_parse_and_process(&format, args, &len);
		else
		{
			if (ft_write_and_count(&format, &len) < 0)
				break ;
		}
	}
	va_end(args);
	return (len);
}
