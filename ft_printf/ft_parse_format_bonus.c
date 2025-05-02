/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:01:29 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:09:14 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_parse_flags(const char **format, t_format_info *info)
{
	while (ft_strchr("-0# +", **format))
	{
		if (**format == '-')
			info->left_align = 1;
		else if (**format == '0')
			info->zero_pad = 1;
		else if (**format == '#')
			info->alt_form = 1;
		else if (**format == ' ')
			info->space_sign = 1;
		else if (**format == '+')
			info->plus_sign = 1;
		(*format)++;
	}
	if (info->left_align)
		info->zero_pad = 0;
	if (info->plus_sign)
		info->space_sign = 0;
}

void	ft_parse_width(const char **format, t_format_info *info, va_list args)
{
	if (**format == '*')
	{
		info->width = va_arg(args, int);
		if (info->width < 0)
		{
			info->left_align = 1;
			info->zero_pad = 0;
			info->width = -info->width;
		}
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		info->width = 0;
		while (ft_isdigit(**format))
		{
			info->width = info->width * 10 + (**format - '0');
			(*format)++;
		}
	}
}

void	ft_parse_precision(const char **format, t_format_info *info,
					va_list args)
{
	if (**format != '.')
		return ;
	(*format)++;
	info->precision = 0;
	if (**format == '*')
	{
		info->precision = va_arg(args, int);
		(*format)++;
	}
	else if (ft_isdigit(**format))
	{
		while (ft_isdigit(**format))
		{
			info->precision = info->precision * 10 + (**format - '0');
			(*format)++;
		}
	}
	if (info->precision < 0)
		info->precision = -1;
	if (info->precision != -1)
		info->zero_pad = 0;
}

void	ft_parse_specifier(const char **format, t_format_info *info)
{
	if (ft_strchr("cspdiuxX%", **format))
	{
		info->specifier = **format;
		(*format)++;
	}
	else
	{
		info->error = 1;
	}
}
