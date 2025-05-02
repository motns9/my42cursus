/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:05:27 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:05:28 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_write_char(char c, t_format_info *info)
{
	if (info->error)
		return (-1);
	if (write(1, &c, 1) < 0)
	{
		info->error = 1;
		return (-1);
	}
	info->total_len++;
	return (0);
}

int	ft_write_str(const char *s, int len, t_format_info *info)
{
	int	i;

	if (info->error)
		return (-1);
	i = 0;
	while (i < len)
	{
		if (ft_write_char(s[i], info) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_write_padding(int len, char pad_char, t_format_info *info)
{
	if (info->error)
		return (-1);
	while (len > 0)
	{
		if (ft_write_char(pad_char, info) < 0)
			return (-1);
		len--;
	}
	return (0);
}

int	ft_numlen_base(unsigned long long n, int base_len)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

int	ft_write_num_base(unsigned long long n, t_format_info *info)
{
	if (info->error)
		return (-1);
	if (n >= (unsigned long long)info->base_len)
	{
		if (ft_write_num_base(n / info->base_len, info) < 0)
			return (-1);
	}
	if (ft_write_char(info->base_chars[n % info->base_len], info) < 0)
		return (-1);
	return (0);
}
