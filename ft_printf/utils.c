/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:26:58 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 16:26:59 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_int(int num)
{
	char	*num_str;
	int		count;

	num_str = ft_itoa(num);
	if (!num_str)
		return (0);
	count = ft_process_string(num_str);
	free(num_str);
	return (count);
}

static int	ft_numlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_process_uint(unsigned int num)
{
	int		len;
	char	*str;
	int		i;

	len = ft_numlen(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	i = len - 1;
	if (num == 0)
		str[0] = '0';
	while (num != 0)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	len = ft_process_string(str);
	free(str);
	return (len);
}

int	ft_process_hex(unsigned int num, int uppercase)
{
	char	*hex;
	int		count;

	count = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num >= 16)
		count += ft_process_hex(num / 16, uppercase);
	count += write(1, &hex[num % 16], 1);
	return (count);
}
