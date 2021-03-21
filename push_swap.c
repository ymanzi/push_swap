#include "srcs/push_swap.h"

#include<stdio.h>
void	push_swap_algo(t_array *ar)
{
	int i_chunck;
	int	n_move_top;
	int	n_move_bottom;

	i_chunck = 0;
	while (++i_chunck < ar->nbr_chunck + 1)
	{
		n_move_top = closest_nbr_from_chunk_top(ar, i_chunck, 'a');
		n_move_bottom = closest_nbr_from_chunk_bottom(ar, i_chunck, 'a') + 1;
// printf("top=%d bot=%d\n", n_move_top, n_move_bottom);
// show_stack(ar);
		while ((n_move_top < n_move_bottom ? n_move_top : n_move_bottom) > -1)
		{
			if (n_move_top < n_move_bottom)
				make_move(n_move_top, "ra", ar);
			else
				make_move(n_move_bottom, "rra", ar);
			bring_num_above(ar, "max", 'b');
// show_stack(ar);
			make_move(1, "pb", ar);
// show_stack(ar);
			n_move_top = closest_nbr_from_chunk_top(ar, i_chunck, 'a');
			n_move_bottom = closest_nbr_from_chunk_bottom(ar, i_chunck, 'a') + 1;
		}
	}
	while (ar->size_stack_b)
	{
		bring_num_above(ar, "max", 'b');
		make_move(1, "pa", ar);
	}
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
