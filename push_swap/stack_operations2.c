/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:12:22 by msbita            #+#    #+#             */
/*   Updated: 2025/05/12 11:12:21 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_state *state, int print)
{
	if (state->a->size >= 2)
	{
		rotate_stack(state->a);
		if (print)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_state *state, int print)
{
	if (state->b->size >= 2)
	{
		rotate_stack(state->b);
		if (print)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_state *state, int print)
{
	ra(state, 0);
	rb(state, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

void	rra(t_state *state, int print)
{
	if (state->a->size >= 2)
	{
		reverse_rotate_stack(state->a);
		if (print)
			ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_state *state, int print)
{
	if (state->b->size >= 2)
	{
		reverse_rotate_stack(state->b);
		if (print)
			ft_putstr_fd("rrb\n", 1);
	}
}
