#include "push_swap.h"

void	free_array(t_array *arr)
{
	free(arr->stack_a);
	free(arr->stack_b);
	free(arr);
	arr = 0;
}
