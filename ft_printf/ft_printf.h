#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hash;
	int	space;
	int	plus;
	int	width;
	int	precision;
}	t_flags;

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s, int precision);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char **str);
int		ft_handle_char(char c, t_flags flags);
int		ft_handle_string(char *s, t_flags flags);
int		ft_handle_pointer(void *ptr, t_flags flags);
int		ft_handle_int(int n, t_flags flags);
int		ft_handle_uint(unsigned int n, t_flags flags);
int		ft_handle_hex(unsigned int n, t_flags flags, int uppercase);
int		ft_handle_percent(t_flags flags);
int		ft_count_digits(long long n, int base);
int		ft_count_digits_unsigned(unsigned long long n, int base);
void	ft_putnbr_base(long long n, char *base, int base_len);
void	ft_putnbr_base_unsigned(unsigned long long n, char *base, int base_len);
int		ft_print_width(int width, int size, int zero);
int		ft_format_handler(va_list args, const char **format);
int		ft_parse_flags(const char **format, t_flags *flags);

#endif
