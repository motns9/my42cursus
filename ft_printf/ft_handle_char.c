/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:00:15 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:00:16 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_char(t_format *fmt, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	ft_putchar_len(c, fmt);
}

void	ft_handle_string(t_format *fmt, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr_len(str, fmt);
}

void	ft_handle_percent(t_format *fmt)
{
	ft_putchar_len('%', fmt);
}
