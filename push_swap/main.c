#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	a = init_stack(argc - 1);
	b = init_stack(argc - 1);
	if (!a || !b)
	{
		free_stack(a);
		free_stack(b);
		return (1);
	}
	if (!parse_args(a, argc, argv))
		exit_error(a, b);
	if (!is_sorted(a))
		sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}