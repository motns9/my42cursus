/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:13:14 by msbita            #+#    #+#             */
/*   Updated: 2025/05/12 11:13:15 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min_index;
	int	min_value;

	min_index = 0;
	min_value = stack->data[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->data[i] < min_value)
		{
			min_value = stack->data[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	push_min_to_b(t_state *state)
{
	int	min_index;

	min_index = find_min_index(state->a);
	while (min_index != state->a->size - 1)
	{
		if (min_index > state->a->size / 2)
			rra(state, 1);
		else
			ra(state, 1);
		min_index = find_min_index(state->a);
	}
	pb(state, 1);
}

void	sort_three(t_state *state)
{
	int	a;
	int	b;
	int	c;

	if (state->a->size != 3)
		return ;
	a = state->a->data[2];
	b = state->a->data[1];
	c = state->a->data[0];
	if (a > b && b < c && a < c)
		sa(state, 1);
	else if (a > b && b > c)
	{
		sa(state, 1);
		rra(state, 1);
	}
	else if (a > b && b < c && a > c)
		ra(state, 1);
	else if (a < b && b > c && a < c)
	{
		sa(state, 1);
		ra(state, 1);
	}
	else if (a < b && b > c && a > c)
		rra(state, 1);
}

void	sort_four(t_state *state)
{
	push_min_to_b(state);
	sort_three(state);
	pa(state, 1);
}

void	sort_five(t_state *state)
{
	push_min_to_b(state);
	push_min_to_b(state);
	sort_three(state);
	pa(state, 1);
	pa(state, 1);
}
