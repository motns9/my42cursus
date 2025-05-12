/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:40:36 by msbita            #+#    #+#             */
/*   Updated: 2025/04/26 16:40:37 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_split_array(char **array, size_t words_allocated)
{
	size_t	i;

	i = 0;
	while (i < words_allocated)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	*allocate_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static int	fill_array(char **result_array, char const *s, char c, size_t wc)
{
	size_t	i;
	size_t	word_index;

	i = 0;
	word_index = 0;
	while (word_index < wc)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			result_array[word_index] = allocate_word(&s[i], c);
			if (!result_array[word_index])
			{
				free_split_array(result_array, word_index);
				return (0);
			}
			while (s[i] && s[i] != c)
				i++;
			word_index++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result_array;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result_array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result_array)
		return (NULL);
	if (!fill_array(result_array, s, c, word_count))
		return (NULL);
	result_array[word_count] = NULL;
	return (result_array);
}
