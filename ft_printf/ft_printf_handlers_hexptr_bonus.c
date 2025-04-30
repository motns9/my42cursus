#include "ft_printf_bonus.h"

void	ft_handle_hex(t_format_info *info, va_list args, int uppercase)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	if (uppercase)
		info->base_chars = "0123456789ABCDEF";
	else
		info->base_chars = "0123456789abcdef";
	info->base_len = 16;
	info->is_negative = 0;
	info->plus_sign = 0;
	info->space_sign = 0;
	ft_calculate_padding(info, num);
	ft_write_num_padded(info, num);
}

void	ft_handle_null_ptr(t_format_info *info)
{
	char	*null_str;
	int		len;
	int		padding;

	null_str = "(nil)";
	len = ft_strlen(null_str);
	if (info->precision != -1 && info->precision < len)
		len = info->precision;
	padding = info->width - len;
	if (padding < 0)
		padding = 0;
	ft_print_str(info, null_str, len, padding);
}

void	ft_handle_ptr(t_format_info *info, va_list args)
{
	unsigned long long	ptr_val;

	ptr_val = (unsigned long long)va_arg(args, void *);
	if (ptr_val == 0 && info->precision != 0)
	{
		ft_handle_null_ptr(info);
		return ;
	}
	info->base_chars = "0123456789abcdef";
	info->base_len = 16;
	info->alt_form = 1;
	info->plus_sign = 0;
	info->space_sign = 0;
	info->is_negative = 0;
	ft_calculate_padding(info, ptr_val);
	ft_write_num_padded(info, ptr_val);
}
