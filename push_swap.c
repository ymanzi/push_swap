#include "srcs/push_swap.h"

#include<stdio.h>
void	bring_number(t_array *ar, int value, char i_stack)
{
	int move_top;
	int	move_bottom;

	move_top = move_from_top(ar, value, i_stack);
	move_bottom = move_from_bottom(ar, value, i_stack);
	if (i_stack == 'a')
		(move_top < move_bottom ? make_move(move_top, "ra", ar): make_move(move_bottom, "rra", ar));
	else
		(move_top < move_bottom ? make_move(move_top, "rb", ar): make_move(move_bottom, "rrb", ar));
}

void	push_swap_algo(t_array *ar)
{
	int	i;
	int	size_b;
	int	max_global;
	int	max_b;
	int min_b;
	int i_chunck;
	int	n_move_top;
	int	n_move_bottom;

	i_chunck = ar->nbr_chunck + 1;
	// size_b = 0;
	// i = 0;
	// max_global = ar->full_sorted[ar->size_stack_a - 1];
	while (--i_chunck > 0)
	{
		n_move_top = closest_nbr_from_chunk_top(ar, i_chunck, 'a');
		n_move_bottom = closest_nbr_from_chunk_bottom(ar, i_chunck, 'a');
		while (n_move_top > -1)
		{
			(n_move_bottom < n_move_top ? make_move(n_move_bottom, "rra", ar): make_move(n_move_top, "ra", ar));
			make_move(1, "pb", ar);
			n_move_top = closest_nbr_from_chunk_top(ar, i_chunck, 'a');
			n_move_bottom = closest_nbr_from_chunk_bottom(ar, i_chunck, 'a');
		}
		// if (n_move_top == -1)
		// 	exit(0);
		// if (i_chunck < ar->nbr_chunck)
		// 	exit(0);
		// while (--i)
		// {
		// 	if (get_chunck_from_number(ar, ar->stack_a[ar->size_stack_a - 1]) == i_chunck)
		// 		make_move(1, "pb", ar);
		// 	// else if (i_chunck < ar->nbr_chunck && ar->stack_a[0] == min_b)
		// 	// 	break ;
		// 	else
		// 		make_move(1, "ra", ar);
		// }
		// if (i_chunck < ar->nbr_chunck)
		// 	bring_number(ar, min_b, 'a');
		// min_b = get_minmax(ar, 'b', "min");
		// while (ar->size_stack_b)
		// {
		// 	bring_num_above(ar, "max", 'b');
		// 	make_move(1, "pa", ar);
		// }
		// make_move(1, "ra", ar);
	}
	exit(0);
	while (ar->size_stack_b)
	{
		bring_num_above(ar, "max", 'b');
		make_move(1, "pa", ar);
	}
	exit(0);
}

void	one_arg(char *str, t_array **array)
{
	char	**tab_arg;
	char	*tmp;
	int		argc;

	tmp = ft_strjoin("prog ", str);
	tab_arg = ft_split(tmp, ' ');
	argc = get_size_argv(tab_arg);
	free(tmp);
	if (!(check_argv(argc, tab_arg))
	|| !(*array = argv_to_array(argc, tab_arg)))
	{
		free_double_tab(tab_arg);
		error_handling(*array, 0, 1);
		return ;
	}
	if ((*array)->size_stack_a > 1)
		push_swap_algo(*array);
	// show_stack(array);
	free_double_tab(tab_arg);
	error_handling(*array, 0, 0);
}

int		main(int argc, char **argv)
{
	t_array	*array;

	array = NULL;
	if (argc == 1)
		return (0);
	if (argc == 2 && just_digit_and_space(argv[1]))
		one_arg(argv[1], &array);
	else
	{
		if (!(check_argv(argc, argv))
		|| !(array = argv_to_array(argc, argv)))
			return (error_handling(array, 0, 1));
		if (array->size_stack_a > 1)
			push_swap_algo(array);
		// show_stack(array);
		error_handling(array, 0, 0);
	}
	return (0);
}
