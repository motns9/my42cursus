/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:32:39 by msbita            #+#    #+#             */
/*   Updated: 2025/04/26 16:32:41 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	target;
	char	*last_found;
	size_t	i;

	target = (char)c;
	last_found = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == target)
			last_found = (char *)&s[i];
		i++;
	}
	if (target == '\0')
		return ((char *)&s[i]);
	return (last_found);
}
