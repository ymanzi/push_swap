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

void	check_sorted(t_array *array)
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
	if (ret)
		write(1, "OK\n", 3);
	else
		write(1, "K0\n", 3);
}

#include <stdio.h>
void	show_stack(t_array *array)
{
	int		i;
	int		size_a;
	int		size_b;
	char	*str;

	size_a = array->size_stack_a;
	size_b = array->size_stack_b;
	str = "SA   SB\n";
	write(1, str, ft_strlen(str));
	i = (size_a > size_b ? size_a : size_b);
	while (--i >= 0)
	{
		if (i < size_a)
			ft_putnbr_fd(array->stack_a[i], 1);
		else
			write(1, "       ", 7);
		write(1, "            ", 8);
		if (i < size_b)
			ft_putnbr_fd(array->stack_b[i], 1);
		write(1, "\n", 1);
	}
	str = "============ SORTED ============\n";
	write(1, str, ft_strlen(str));
	i = -1;
	while (++i < size_b + size_a)
	{
		ft_putnbr_fd(array->full_sorted[i], 1);
		write(1, " ", 1);
	}
	str = "\n============ chunck ============\n";
	write(1, str, ft_strlen(str));
	i = -1;
	while (++i < array->nbr_chunck + 1)
	{
		ft_putnbr_fd(array->chunck[i], 1);
		write(1, " ", 1);
	}
	str = "\n-----------------------------------------\n";
}
