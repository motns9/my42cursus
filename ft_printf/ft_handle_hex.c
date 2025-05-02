/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:00:52 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:00:52 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle_hex(t_format *fmt, va_list args, int uppercase)
{
	unsigned int	n;
	char			*base;

	n = va_arg(args, unsigned int);
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ft_putnbr_base(n, base, fmt);
}

void	ft_handle_pointer(t_format *fmt, va_list args)
{
	void			*ptr;
	unsigned long	ptr_val;

	ptr = va_arg(args, void *);
	ptr_val = (unsigned long)ptr;
	if (ptr == NULL)
	{
		ft_putstr_len("(nil)", fmt);
		return ;
	}
	ft_putstr_len("0x", fmt);
	ft_putnbr_base(ptr_val, "0123456789abcdef", fmt);
}
