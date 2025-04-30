#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s, int precision)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i] && (precision == -1 || i < precision))
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char **str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (ft_isdigit(**str))
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result * sign);
}
