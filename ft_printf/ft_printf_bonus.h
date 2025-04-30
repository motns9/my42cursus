#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_format_info
{
	int		left_align;
	int		zero_pad;
	int		precision;
	int		width;
	int		alt_form;
	int		space_sign;
	int		plus_sign;
	int		total_len;
	char	specifier;
	int		error;
	int		is_negative;
	int		base_len;
	char	*base_chars;
	int		nbr_len;
	int		padding;
	int		prefix_len;
}			t_format_info;

int		ft_printf(const char *format, ...);
void	ft_parse_flags(const char **format, t_format_info *info);
void	ft_parse_width(const char **format, t_format_info *info, va_list args);
void	ft_parse_precision(const char **fmt, t_format_info *info, va_list args);
void	ft_parse_specifier(const char **format, t_format_info *info);
void	ft_parse_and_process(const char **fmt, va_list args, int *len_ptr);
void	ft_process_format(t_format_info *info, va_list args);
void	ft_handle_char(t_format_info *info, va_list args);
void	ft_handle_string(t_format_info *info, va_list args);
void	ft_handle_percent(t_format_info *info);
void	ft_handle_int(t_format_info *info, va_list args);
void	ft_handle_uint(t_format_info *info, va_list args, char *base,
			int b_len);
void	ft_handle_hex(t_format_info *info, va_list args, int uppercase);
void	ft_handle_ptr(t_format_info *info, va_list args);
void	ft_calculate_padding(t_format_info *info, unsigned long long n);
void	ft_write_num_padded(t_format_info *info, unsigned long long n);
int		ft_write_char(char c, t_format_info *info);
int		ft_write_str(const char *s, int len, t_format_info *info);
int		ft_write_padding(int len, char pad_char, t_format_info *info);
int		ft_numlen_base(unsigned long long n, int base_len);
int		ft_write_num_base(unsigned long long n, t_format_info *info);
int		ft_write_prefix(t_format_info *info, unsigned long long n);
void	ft_handle_null_ptr(t_format_info *info);
void	ft_init_format_info(t_format_info *info, int current_len);
void	ft_print_str(t_format_info *info, char *str, int len, int padding);
char	*ft_get_null_str(void);

#endif
