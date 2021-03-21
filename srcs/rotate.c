#include "push_swap.h"

/*
** rotate a
** shift up all elements of stack a by 1.
** The first element becomes the last one.
*/

void	ra(t_array *array)
{
	int	stack_size;
	int	*stack;
	int	i;

	i = 0;
	stack_size = array->size_stack_a;
	stack = array->stack_a;
	if (stack_size > 1)
	{
		while (++i < stack_size)
			ft_swap(stack, stack + i);
	}
}

/*
** rotate b
** shift up all elements of stack b by 1.
** The first element becomes the last one.
*/

void	rb(t_array *array)
{
	int	stack_size;
	int	*stack;
	int	i;

	i = 0;
	stack_size = array->size_stack_b;
	stack = array->stack_b;
	if (stack_size > 1)
	{
		while (++i < stack_size)
			ft_swap(stack, stack + i);
	}
}

/*
** rotate b and b
*/

void	rr(t_array *array)
{
	ra(array);
	rb(array);
}
