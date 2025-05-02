/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:27:04 by msbita            #+#    #+#             */
/*   Updated: 2025/05/02 16:27:05 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_process_char(char c);
int	ft_process_string(char *str);
int	ft_process_pointer(void *ptr);
int	ft_process_int(int num);
int	ft_process_uint(unsigned int num);
int	ft_process_hex(unsigned int num, int uppercase);
int	ft_process_percent(void);

#endif
