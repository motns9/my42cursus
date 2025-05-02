/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:03:53 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 14:03:54 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_handle_int(t_format_info *info, va_list args)
{
	unsigned long long	num;
	long long			n_arg;

	n_arg = va_arg(args, int);
	info->base_chars = "0123456789";
	info->base_len = 10;
	info->is_negative = (n_arg < 0);
	if (info->is_negative)
		num = -n_arg;
	else
		num = n_arg;
	ft_calculate_padding(info, num);
	ft_write_num_padded(info, num);
}

void	ft_handle_uint(t_format_info *info, va_list args, char *base, int b_len)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	info->base_chars = base;
	info->base_len = b_len;
	info->is_negative = 0;
	info->plus_sign = 0;
	info->space_sign = 0;
	ft_calculate_padding(info, num);
	ft_write_num_padded(info, num);
}
