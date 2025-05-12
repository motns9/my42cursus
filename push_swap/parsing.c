/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:09:05 by msbita            #+#    #+#             */
/*   Updated: 2025/05/12 10:11:06 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->data[i] == stack->data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_state *state)
{
	int		i;
	long	num;

	state->a = create_stack(argc - 1);
	state->b = create_stack(argc - 1);
	if (!state->a || !state->b)
		return (0);
	state->total_size = argc - 1;
	i = argc - 1;
	while (i >= 1)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		push_to_stack(state->a, (int)num);
		i--;
	}
	if (has_duplicates(state->a))
		return (0);
	return (1);
}
