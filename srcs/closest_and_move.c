#include "push_swap.h"

int		closest_nbr_from_chunk_top(t_array *ar, int i_chunck, char i_stack)
{
	int	i;
	int	size;
	int	*stack;

	set_stack_and_size(ar, &stack, &size, i_stack);
	i = -1;
	while (size - ++i > 0)
	{
		if (get_chunck_from_number(ar, stack[size - i - 1]) == i_chunck)
			return (i);
	}
	return (-1);
}

int		closest_nbr_from_chunk_bottom(t_array *ar, int i_chunck, char i_stack)
{
	int	i;
	int	size;
	int	*stack;

	set_stack_and_size(ar, &stack, &size, i_stack);
	i = -1;
	while (++i < size)
	{
		if (get_chunck_from_number(ar, stack[i]) == i_chunck)
			return (i);
	}
	return (-1);
}

int		move_from_top(t_array *array, int number, char ind_stack)
{
	int	i;
	int	size;
	int	*stack;

	i = -1;
	set_stack_and_size(array, &stack, &size, ind_stack);
	while (size - ++i > 0)
	{
		if (stack[size - i - 1] == number)
			return (i);
	}
	return (-1);
}

void	make_move(int times, char *operation, t_array *array)
{
	int		i;

	i = -1;
	while (++i < times)
	{
		make_operation_on_array(array, operation);
		write(1, operation, ft_strlen(operation));
		write(1, "\n", 1);
	}
}
