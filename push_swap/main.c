/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbita <msbita@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 09:59:43 by msbita            #+#    #+#             */
/*   Updated: 2025/05/11 10:00:43 by msbita           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_dispatcher(t_state *state)
{
	if (state->a->size == 2)
	{
		if (state->a->data[0] > state->a->data[1])
			sa(state, 1);
	}
	else if (state->a->size == 3)
		sort_three(state);
	else if (state->a->size == 4)
		sort_four(state);
	else if (state->a->size == 5)
		sort_five(state);
	else
		sort_big(state);
}

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &state))
		error_exit();
	if (!is_sorted(state.a))
		sort_dispatcher(&state);
	free_state(&state);
	return (0);
}
