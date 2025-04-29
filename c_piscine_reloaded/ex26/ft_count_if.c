/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:25:11 by msbita            #+#    #+#             */
/*   Updated: 2025/04/26 13:29:40 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (tab == NULL || f == NULL)
		return (0);
	while (tab[i] != 0)
	{
		if (f(tab[i]) != 0)
		{
			count++;
		}
		i++;
	}
	return (count);
}
