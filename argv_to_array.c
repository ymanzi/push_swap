#include "push_swap.h"

t_array	*argv_to_array(int argc, char **argv)
{
	int		i;
	t_array	*ar;

	i = 0;
	if (!(ar = (t_array*)malloc(sizeof(t_array)))
	|| !(ar->stack_a = (int*)malloc(sizeof(int) * (argc - 1)))
	|| !(ar->stack_b = (int*)malloc(sizeof(int) * (argc - 1))))
		return (0);
	ar->size_stack_a = argc - 1;
	ar->size_stack_b = 0;
	while (++i < argc)
		ar->stack_a[i - 1] = ft_atoi(argv[i]);
	return (ar);
}