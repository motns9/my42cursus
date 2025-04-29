/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:24:51 by msbita            #+#    #+#             */
/*   Updated: 2025/04/26 13:24:52 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*range_tab;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	size = max - min;
	range_tab = (int *)malloc(sizeof(int) * size);
	if (range_tab == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		range_tab[i] = min + i;
		i++;
	}
	return (range_tab);
}
