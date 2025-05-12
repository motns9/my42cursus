/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:12:03 by msbita            #+#    #+#             */
/*   Updated: 2025/05/12 11:12:04 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_state *state, int print)
{
	if (state->a->size >= 2)
	{
		swap_elements(state->a);
		if (print)
			ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_state *state, int print)
{
	if (state->b->size >= 2)
	{
		swap_elements(state->b);
		if (print)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_state *state, int print)
{
	sa(state, 0);
	sb(state, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

void	pa(t_state *state, int print)
{
	int	value;

	if (state->b->size > 0)
	{
		value = pop_from_stack(state->b);
		push_to_stack(state->a, value);
		if (print)
			ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_state *state, int print)
{
	int	value;

	if (state->a->size > 0)
	{
		value = pop_from_stack(state->a);
		push_to_stack(state->b, value);
		if (print)
			ft_putstr_fd("pb\n", 1);
	}
}
