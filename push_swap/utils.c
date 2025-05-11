/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:01:24 by msbita            #+#    #+#             */
/*   Updated: 2025/05/11 10:01:25 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = malloc(sizeof(int) * capacity);
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->data)
			free(stack->data);
		free(stack);
	}
}

void	free_state(t_state *state)
{
	free_stack(state->a);
	free_stack(state->b);
}

void	swap_elements(t_stack *stack)
{
	int	temp;

	if (stack->size >= 2)
	{
		temp = stack->data[stack->size - 1];
		stack->data[stack->size - 1] = stack->data[stack->size - 2];
		stack->data[stack->size - 2] = temp;
	}
}

int	stack_is_empty(t_stack *stack)
{
	return (stack->size == 0);
}
