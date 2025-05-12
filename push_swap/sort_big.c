/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:13:22 by msbita            #+#    #+#             */
/*   Updated: 2025/05/12 11:24:50 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_max_bits(t_stack *stack)
{
	int	max_num;
	int	max_bits;

	max_num = stack->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	simplify_numbers(t_state *state)
{
	int	*simplified;
	int	i;
	int	j;
	int	count;

	simplified = malloc(sizeof(int) * state->a->size);
	if (!simplified)
		error_exit();
	i = 0;
	while (i < state->a->size)
	{
		count = 0;
		j = 0;
		while (j < state->a->size)
		{
			if (state->a->data[j] < state->a->data[i])
				count++;
			j++;
		}
		simplified[i] = count;
		i++;
	}
	ft_memcpy(state->a->data, simplified, sizeof(int) * state->a->size);
	free(simplified);
}

void	radix_sort(t_state *state)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	simplify_numbers(state);
	max_bits = get_max_bits(state->a);
	i = 0;
	while (i < max_bits)
	{
		size = state->a->size;
		j = 0;
		while (j < size)
		{
			if (((state->a->data[state->a->size - 1] >> i) & 1) == 0)
				pb(state, 1);
			else
				ra(state, 1);
			j++;
		}
		while (state->b->size > 0)
			pa(state, 1);
		i++;
	}
}

void	sort_big(t_state *state)
{
	radix_sort(state);
}
