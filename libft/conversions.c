/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:27:20 by msbita            #+#    #+#             */
/*   Updated: 2025/05/10 14:24:15 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_process_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_process_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
		count++;
	return (write(1, str, count));
}

int	ft_process_percent(void)
{
	return (write(1, "%", 1));
}

static int	ft_putaddr(unsigned long addr)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (addr >= 16)
		count += ft_putaddr(addr / 16);
	count += write(1, &hex[addr % 16], 1);
	return (count);
}

int	ft_process_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putaddr((unsigned long)ptr);
	return (count);
}
