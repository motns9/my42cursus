/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:12:32 by msbita            #+#    #+#             */
/*   Updated: 2025/05/12 11:12:33 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_state *state, int print)
{
	rra(state, 0);
	rrb(state, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}

void	push_to_stack(t_stack *stack, int value)
{
	if (stack->size < stack->capacity)
	{
		stack->data[stack->size] = value;
		stack->size++;
	}
}

int	pop_from_stack(t_stack *stack)
{
	int	value;

	if (stack->size > 0)
	{
		value = stack->data[stack->size - 1];
		stack->size--;
		return (value);
	}
	return (0);
}

void	rotate_stack(t_stack *stack)
{
	int	i;
	int	first;

	if (stack->size >= 2)
	{
		first = stack->data[stack->size - 1];
		i = stack->size - 1;
		while (i > 0)
		{
			stack->data[i] = stack->data[i - 1];
			i--;
		}
		stack->data[0] = first;
	}
}

void	reverse_rotate_stack(t_stack *stack)
{
	int	i;
	int	last;

	if (stack->size >= 2)
	{
		last = stack->data[0];
		i = 0;
		while (i < stack->size - 1)
		{
			stack->data[i] = stack->data[i + 1];
			i++;
		}
		stack->data[stack->size - 1] = last;
	}
}
