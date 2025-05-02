/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:59:52 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 13:59:53 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char c, t_format *fmt)
{
	if (fmt->error)
		return (-1);
	if (write(1, &c, 1) < 0)
	{
		fmt->error = 1;
		return (-1);
	}
	fmt->total_len++;
	return (1);
}

int	ft_putstr_len(char *s, t_format *fmt)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	if (fmt->error)
		return (-1);
	while (s[i])
	{
		if (ft_putchar_len(s[i], fmt) < 0)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(unsigned long n, char *base, t_format *fmt)
{
	int	base_len;
	int	len;

	if (fmt->error)
		return (-1);
	base_len = ft_strlen(base);
	len = 0;
	if (n >= (unsigned long)base_len)
	{
		len = ft_putnbr_base(n / base_len, base, fmt);
		if (len < 0)
			return (-1);
	}
	if (ft_putchar_len(base[n % base_len], fmt) < 0)
		return (-1);
	return (len + 1);
}
