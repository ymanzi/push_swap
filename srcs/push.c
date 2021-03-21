#include "push_swap.h"

/*
** push a
** take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
*/

void	pa(t_array *array)
{
	if (array->size_stack_b > 0)
	{
		array->size_stack_b--;
		array->stack_a[array->size_stack_a] =
			array->stack_b[array->size_stack_b];
		array->size_stack_a++;
	}
}

/*
** push b
** take the first element at the top of a and put it at the top of b
** Do nothing if a is empty.
*/

void	pb(t_array *array)
{
	if (array->size_stack_a > 0)
	{
		array->size_stack_a--;
		array->stack_b[array->size_stack_b] =
			array->stack_a[array->size_stack_a];
		array->size_stack_b++;
	}
}
