/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:54:44 by msbita            #+#    #+#             */
/*   Updated: 2025/04/28 16:54:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
je ne sais pas si je dois gerer les overflows ou pas
#include "libft.h"
#include <limits.h>

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

static int	parse_digits(const char *str, int sign)
{
	long long	result;
	int			digit;

	result = 0;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (sign == 1 && result > (LLONG_MAX - digit) / 10)
			return (-1);
		if (sign == -1 && (-result) < (LLONG_MIN + digit) / 10)
			return (0);
		result = result * 10 + digit;
		str++;
	}
	return ((int)(result * sign));
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	return (parse_digits(str, sign));
}
*/