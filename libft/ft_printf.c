/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:27:13 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 16:27:14 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_handler(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		return (ft_process_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_process_string(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_process_pointer(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_process_int(va_arg(args, int)));
	else if (format == 'u')
		return (ft_process_uint(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_process_hex(va_arg(args, unsigned int), 0));
	else if (format == 'X')
		return (ft_process_hex(va_arg(args, unsigned int), 1));
	else if (format == '%')
		return (ft_process_percent());
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_format_handler(args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			count += ft_process_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
