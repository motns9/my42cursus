/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:23:52 by msbita            #+#    #+#             */
/*   Updated: 2025/04/26 13:23:53 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	square;

	if (nb <= 0)
	{
		return (0);
	}
	i = 1;
	square = 1;
	while (square <= (long)nb && square > 0 && i <= 46341)
	{
		if (square == (long)nb)
		{
			return ((int)i);
		}
		i++;
		square = i * i;
	}
	return (0);
}
