#include "srcs/push_swap.h"

#include<stdio.h>
void	push_swap_algo(t_array *ar)
{
	int	i;
	int	j;
	int	max_global;
	int	min_b;
	int i_chunck;

	i_chunck = ar->nbr_chunck + 1;
	j = 0;
	max_global = ar->full_sorted[ar->size_stack_a - 1];
	while (i_chunck - ++j > 0)
	{
		i = ar->size_stack_a + 1;
		{
			while (--i)
			{
				if (get_chunck_from_number(ar, ar->stack_a[ar->size_stack_a - 1]) == i_chunck - j)
					make_move(1, "pb", ar);
				else if (get_chunck_from_number(ar, ar->stack_a[ar->size_stack_a - 1]) == j)
				{
					make_move(1, "pb", ar);
					make_move(1, "rb", ar);
				}
				else
					make_move(1, "ra", ar);
				// if (closest_nbr_from_chunk_top(ar, i_chunck - j, 'a') == -1)
				// 	break ;
			}
		}
	}
	while (ar->size_stack_b)
	{
		bring_num_above(ar, "max", 'b');
		make_move(1, "pa", ar);
	}
	// exit(0);
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
