/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:59:22 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 13:59:23 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_format(t_format *fmt)
{
	fmt->total_len = 0;
	fmt->error = 0;
}

static int	ft_process_format(const char **format, va_list args, t_format *fmt)
{
	(*format)++;
	if (**format == 'c')
		ft_handle_char(fmt, args);
	else if (**format == 's')
		ft_handle_string(fmt, args);
	else if (**format == 'p')
		ft_handle_pointer(fmt, args);
	else if (**format == 'd' || **format == 'i')
		ft_handle_int(fmt, args);
	else if (**format == 'u')
		ft_handle_uint(fmt, args);
	else if (**format == 'x')
		ft_handle_hex(fmt, args, 0);
	else if (**format == 'X')
		ft_handle_hex(fmt, args, 1);
	else if (**format == '%')
		ft_handle_percent(fmt);
	else
		return (0);
	(*format)++;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	fmt;

	if (!format)
		return (-1);
	ft_init_format(&fmt);
	va_start(args, format);
	while (*format && !fmt.error)
	{
		if (*format == '%')
		{
			if (!ft_process_format(&format, args, &fmt))
				break ;
		}
		else
		{
			if (ft_putchar_len(*format, &fmt) < 0)
				break ;
			format++;
		}
	}
	va_end(args);
	if (fmt.error)
		return (-1);
	return (fmt.total_len);
}
