#include "push_swap.h"

/*
** rotate a
** shift down all elements of stack a by 1.
** The last element becomes the first one.
*/

void	rra(t_array *array)
{
	int	stack_size;
	int	*stack;
	int	i;

	stack_size = array->size_stack_a;
	stack = array->stack_a;
	i = stack_size;
	if (stack_size > 1)
	{
		while (--i > 0)
			ft_swap(stack, stack + i);
	}
}

/*
** rotate b
** shift down all elements of stack b by 1.
** The last element becomes the first one.
*/

void	rrb(t_array *array)
{
	int	stack_size;
	int	*stack;
	int	i;

	stack_size = array->size_stack_b;
	stack = array->stack_b;
	i = stack_size;
	if (stack_size > 1)
	{
		while (--i > 0)
			ft_swap(stack, stack + i);
	}
}

/*
** rotate b and b
*/

void	rrr(t_array *array)
{
	rra(array);
	rrb(array);
}
