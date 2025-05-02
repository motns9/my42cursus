/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_format_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:02:20 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:02:21 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_format_info(t_format_info *info, int current_len)
{
	info->left_align = 0;
	info->zero_pad = 0;
	info->precision = -1;
	info->width = 0;
	info->alt_form = 0;
	info->space_sign = 0;
	info->plus_sign = 0;
	info->total_len = current_len;
	info->specifier = 0;
	info->error = 0;
	info->is_negative = 0;
	info->base_len = 0;
	info->base_chars = NULL;
	info->nbr_len = 0;
	info->padding = 0;
	info->prefix_len = 0;
}

void	ft_process_format(t_format_info *info, va_list args)
{
	if (info->specifier == 'c')
		ft_handle_char(info, args);
	else if (info->specifier == 's')
		ft_handle_string(info, args);
	else if (info->specifier == '%')
		ft_handle_percent(info);
	else if (info->specifier == 'd' || info->specifier == 'i')
		ft_handle_int(info, args);
	else if (info->specifier == 'u')
		ft_handle_uint(info, args, "0123456789", 10);
	else if (info->specifier == 'x')
		ft_handle_hex(info, args, 0);
	else if (info->specifier == 'X')
		ft_handle_hex(info, args, 1);
	else if (info->specifier == 'p')
		ft_handle_ptr(info, args);
}

static int	ft_handle_invalid_specifier(const char **format, int *len_ptr)
{
	*len_ptr = -1;
	if (**format == '\0')
	{
		(*format)--;
		return (1);
	}
	return (0);
}

void	ft_parse_and_process(const char **format, va_list args, int *len_ptr)
{
	t_format_info	info;

	ft_init_format_info(&info, *len_ptr);
	(*format)++;
	ft_parse_flags(format, &info);
	ft_parse_width(format, &info, args);
	ft_parse_precision(format, &info, args);
	ft_parse_specifier(format, &info);
	if (info.error)
	{
		if (ft_handle_invalid_specifier(format, len_ptr))
			return ;
	}
	else
		ft_process_format(&info, args);
	if (info.error)
		*len_ptr = -1;
	else
		*len_ptr = info.total_len;
}
