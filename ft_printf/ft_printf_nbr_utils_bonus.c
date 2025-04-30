#include "ft_printf_bonus.h"

void	ft_calculate_padding(t_format_info *info, unsigned long long n)
{
	int	effective_nbr_len;

	info->nbr_len = ft_numlen_base(n, info->base_len);
	if (info->precision == 0 && n == 0)
		info->nbr_len = 0;
	info->prefix_len = 0;
	if (info->specifier == 'd' || info->specifier == 'i')
	{
		if (info->is_negative || info->plus_sign || info->space_sign)
			info->prefix_len = 1;
	}
	else if (info->specifier == 'p' || (info->alt_form && n != 0
			&& (info->specifier == 'x' || info->specifier == 'X')))
		info->prefix_len = 2;
	effective_nbr_len = info->nbr_len;
	if (info->precision != -1 && info->precision > info->nbr_len)
		effective_nbr_len = info->precision;
	info->padding = info->width - info->prefix_len - effective_nbr_len;
	if (info->padding < 0)
		info->padding = 0;
}

static void	ft_write_first_part(t_format_info *info, unsigned long long n,
				char pad_char, int zeroes_to_pad)
{
	if (!info->left_align)
	{
		if (pad_char == ' ')
			ft_write_padding(info->padding, ' ', info);
		ft_write_prefix(info, n);
		if (pad_char == '0')
			ft_write_padding(info->padding, '0', info);
		ft_write_padding(zeroes_to_pad, '0', info);
	}
	else
	{
		ft_write_prefix(info, n);
		ft_write_padding(zeroes_to_pad, '0', info);
	}
}

void	ft_write_num_padded(t_format_info *info, unsigned long long n)
{
	int		zeroes_to_pad;
	char	pad_char;

	pad_char = ' ';
	if (info->zero_pad && info->precision == -1 && !info->left_align)
		pad_char = '0';
	zeroes_to_pad = 0;
	if (info->precision != -1 && info->precision > info->nbr_len)
		zeroes_to_pad = info->precision - info->nbr_len;
	ft_write_first_part(info, n, pad_char, zeroes_to_pad);
	if (info->nbr_len > 0)
		ft_write_num_base(n, info);
	if (info->left_align)
		ft_write_padding(info->padding, ' ', info);
}
