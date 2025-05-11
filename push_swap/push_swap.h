/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 10:00:29 by msbita            #+#    #+#             */
/*   Updated: 2025/05/11 10:00:30 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int		*data;
	int		size;
	int		capacity;
}				t_stack;

typedef struct s_state
{
	t_stack	*a;
	t_stack	*b;
	int		total_size;
}				t_state;

/* parsing.c */
int		parse_args(int argc, char **argv, t_state *state);
int		is_valid_number(char *str);
int		has_duplicates(t_stack *stack);
void	error_exit(void);

/* stack_operations.c */
void	sa(t_state *state, int print);
void	sb(t_state *state, int print);
void	ss(t_state *state, int print);
void	pa(t_state *state, int print);
void	pb(t_state *state, int print);

/* stack_operations2.c */
void	ra(t_state *state, int print);
void	rb(t_state *state, int print);
void	rr(t_state *state, int print);
void	rra(t_state *state, int print);
void	rrb(t_state *state, int print);

/* stack_operations3.c */
void	rrr(t_state *state, int print);
void	push_to_stack(t_stack *stack, int value);
int		pop_from_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

/* sort_small.c */
void	sort_three(t_state *state);
void	sort_four(t_state *state);
void	sort_five(t_state *state);
int		find_min_index(t_stack *stack);
void	push_min_to_b(t_state *state);

/* sort_big.c */
void	sort_big(t_state *state);
void	radix_sort(t_state *state);
int		get_max_bits(t_stack *stack);
int		is_sorted(t_stack *stack);
void	simplify_numbers(t_state *state);

/* utils.c */
t_stack	*create_stack(int capacity);
void	free_stack(t_stack *stack);
void	free_state(t_state *state);
void	swap_elements(t_stack *stack);
int		stack_is_empty(t_stack *stack);

#endif