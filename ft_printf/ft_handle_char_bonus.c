/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:03:00 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:03:01 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_handle_char(t_format_info *info, va_list args)
{
	char	c;
	int		padding;

	c = (char)va_arg(args, int);
	padding = info->width - 1;
	if (padding < 0)
		padding = 0;
	if (!info->left_align)
	{
		if (ft_write_padding(padding, ' ', info) < 0)
			return ;
	}
	if (ft_write_char(c, info) < 0)
		return ;
	if (info->left_align)
	{
		if (ft_write_padding(padding, ' ', info) < 0)
			return ;
	}
}

char	*ft_get_null_str(void)
{
	return ("(null)");
}

void	ft_print_str(t_format_info *info, char *str, int len, int padding)
{
	if (!info->left_align)
	{
		if (ft_write_padding(padding, ' ', info) < 0)
			return ;
	}
	if (ft_write_str(str, len, info) < 0)
		return ;
	if (info->left_align)
	{
		if (ft_write_padding(padding, ' ', info) < 0)
			return ;
	}
}

void	ft_handle_string(t_format_info *info, va_list args)
{
	char	*str;
	int		len;
	int		padding;

	str = va_arg(args, char *);
	if (!str)
		str = ft_get_null_str();
	len = ft_strlen(str);
	if (info->precision != -1 && info->precision < len)
		len = info->precision;
	padding = info->width - len;
	if (padding < 0)
		padding = 0;
	ft_print_str(info, str, len, padding);
}

void	ft_handle_percent(t_format_info *info)
{
	int		padding;
	char	pad_char;

	padding = info->width - 1;
	if (padding < 0)
		padding = 0;
	pad_char = ' ';
	if (info->zero_pad && !info->left_align)
		pad_char = '0';
	if (!info->left_align)
	{
		if (ft_write_padding(padding, pad_char, info) < 0)
			return ;
	}
	if (ft_write_char('%', info) < 0)
		return ;
	if (info->left_align)
	{
		if (ft_write_padding(padding, ' ', info) < 0)
			return ;
	}
}
