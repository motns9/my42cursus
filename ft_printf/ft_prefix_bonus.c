/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:06:39 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:06:40 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_handle_sign_prefix(t_format_info *info)
{
	if (info->is_negative)
	{
		if (ft_write_char('-', info) < 0)
			return (-1);
	}
	else if (info->plus_sign)
	{
		if (ft_write_char('+', info) < 0)
			return (-1);
	}
	else if (info->space_sign)
	{
		if (ft_write_char(' ', info) < 0)
			return (-1);
	}
	return (0);
}

static int	ft_handle_alt_form_prefix(t_format_info *info, unsigned long long n)
{
	if (info->alt_form && n != 0 && info->specifier != 'p')
	{
		if (info->specifier == 'x')
		{
			if (ft_write_str("0x", 2, info) < 0)
				return (-1);
		}
		else if (info->specifier == 'X')
		{
			if (ft_write_str("0X", 2, info) < 0)
				return (-1);
		}
	}
	else if (info->specifier == 'p')
	{
		if (ft_write_str("0x", 2, info) < 0)
			return (-1);
	}
	return (0);
}

int	ft_write_prefix(t_format_info *info, unsigned long long n)
{
	if (info->specifier == 'd' || info->specifier == 'i')
	{
		if (ft_handle_sign_prefix(info) < 0)
			return (-1);
	}
	else if (info->specifier == 'x' || info->specifier == 'X'
		|| info->specifier == 'p')
	{
		if (ft_handle_alt_form_prefix(info, n) < 0)
			return (-1);
	}
	return (0);
}
