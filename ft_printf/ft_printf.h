/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 13:58:52 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 13:58:53 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_format
{
	int		total_len;
	int		error;
}			t_format;

int		ft_printf(const char *format, ...);
void	ft_handle_char(t_format *fmt, va_list args);
void	ft_handle_string(t_format *fmt, va_list args);
void	ft_handle_pointer(t_format *fmt, va_list args);
void	ft_handle_int(t_format *fmt, va_list args);
void	ft_handle_uint(t_format *fmt, va_list args);
void	ft_handle_hex(t_format *fmt, va_list args, int uppercase);
void	ft_handle_percent(t_format *fmt);
int		ft_putchar_len(char c, t_format *fmt);
int		ft_putstr_len(char *s, t_format *fmt);
int		ft_putnbr_base(unsigned long n, char *base, t_format *fmt);

#endif