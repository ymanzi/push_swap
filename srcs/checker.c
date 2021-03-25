#include "push_swap.h"

void	make_operation_on_array(t_array *array, char *operation)
{
	if (!ft_strncmp(operation, "sa", 4))
		sa(array);
	else if (!ft_strncmp(operation, "sb", 4))
		sb(array);
	else if (!ft_strncmp(operation, "ss", 4))
		ss(array);
	else if (!ft_strncmp(operation, "pa", 4))
		pa(array);
	else if (!ft_strncmp(operation, "pb", 4))
		pb(array);
	else if (!ft_strncmp(operation, "ra", 4))
		ra(array);
	else if (!ft_strncmp(operation, "rb", 4))
		rb(array);
	else if (!ft_strncmp(operation, "rr", 4))
		rr(array);
	else if (!ft_strncmp(operation, "rra", 4))
		rra(array);
	else if (!ft_strncmp(operation, "rrb", 4))
		rrb(array);
	else if (!ft_strncmp(operation, "rrr", 4))
		rrr(array);
}

int		error_handling(t_array *array, char *line, int ind)
{
	if (array)
		free_array(array);
	if (line)
		free(line);
	if (ind)
		write(2, "Error\n", 6);
	return (0);
}

int		check_sorted(t_array *array)
{
	int	i;
	int ret;
	int	*stack;

	ret = 1;
	stack = array->stack_a;
	i = array->size_stack_a;
	while (--i > 0)
	{
		if (stack[i] > stack[i - 1])
		{
			ret = 0;
			break ;
		}
	}
	if (array->size_stack_b)
		ret = 0;
	return (ret);
}
