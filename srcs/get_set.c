#include "push_swap.h"

void	set_stack_and_size(t_array *ar, int **stack, int *size, char ind_stack)
{
	if (ind_stack == 'a')
	{
		*stack = ar->stack_a;
		*size = ar->size_stack_a;
	}
	else
	{
		*stack = ar->stack_b;
		*size = ar->size_stack_b;
	}
}

int		get_chunck_from_number(t_array *ar, int value)
{
	int	j;
	int	i;

	i = -1;
	while (++i < (ar->size_stack_a + ar->size_stack_b))
	{
		if (ar->full_sorted[i] == value)
		{
			j = 0;
			while (++j < ar->nbr_chunck + 1)
			{
				if (i >= ar->chunck[j - 1] && i < ar->chunck[j])
					return (j);
			}
		}
	}
	return (-1);
}

int		get_minmax(t_array *ar, char i_stack, char *kind)
{
	int	i;
	int	minmax;
	int	size;
	int	*stack;

	set_stack_and_size(ar, &stack, &size, i_stack);
	i = 0;
	minmax = stack[0];
	while (++i < size)
	{
		if (!ft_strncmp(kind, "min", 4))
		{
			if (minmax > stack[i])
				minmax = stack[i];
		}
		else
		{
			if (minmax < stack[i])
				minmax = stack[i];
		}
	}
	return (minmax);
}

void	bring_num_above(t_array *ar, char *kind, char i_stack)
{
	int	nbr_move;

	nbr_move = move_from_top(ar, get_minmax(ar, i_stack, kind), i_stack);
	if (i_stack == 'a' && nbr_move <= ar->size_stack_a / 2)
		make_move(nbr_move, "rra", ar);
	else if (i_stack == 'a')
		make_move(ar->size_stack_a - nbr_move, "ra", ar);
	else if (i_stack == 'b' && nbr_move <= ar->size_stack_b / 2)
		make_move(nbr_move, "rb", ar);
	else
		make_move(ar->size_stack_b - nbr_move, "rrb", ar);
}

int		max_or_min(t_array *ar)
{
	int	min_move;
	int	max_move;

	max_move = move_from_top(ar, get_minmax(ar, 'b', "max"), 'b');
	if (max_move > ar->size_stack_b / 2)
		max_move = ar->size_stack_b - max_move;
	min_move = move_from_top(ar, get_minmax(ar, 'b', "min"), 'b');
	if (min_move > ar->size_stack_b / 2)
		min_move = ar->size_stack_b - min_move;
	return (min_move < max_move ? 0: 1);
}