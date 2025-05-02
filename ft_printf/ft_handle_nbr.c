/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:00:35 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:00:39 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_int(t_format *fmt, va_list args)
{
	int	n;

	n = va_arg(args, int);
	if (n < 0)
	{
		ft_putchar_len('-', fmt);
		if (n == -2147483648)
		{
			ft_putstr_len("2147483648", fmt);
			return ;
		}
		n = -n;
	}
	ft_putnbr_base((unsigned int)n, "0123456789", fmt);
}

void	ft_handle_uint(t_format *fmt, va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbr_base(n, "0123456789", fmt);
}
