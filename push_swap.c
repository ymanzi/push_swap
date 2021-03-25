#include "srcs/push_swap.h"

void	from_a_to_b(t_array *ar, int j, int i_chunck)
{
	int	i;

	while (i_chunck - ++j >= 0)
	{
		i = ar->size_stack_a + 1;
		{
			while (--i)
			{
				if (get_chunck_from_number(ar,
				ar->stack_a[ar->size_stack_a - 1]) == i_chunck + j - 1)
					make_move(1, "pb", ar);
				else if (get_chunck_from_number(ar,
				ar->stack_a[ar->size_stack_a - 1]) == i_chunck - j)
				{
					make_move(1, "pb", ar);
					make_move(1, "rb", ar);
				}
				else
					make_move(1, "ra", ar);
			}
		}
	}
}

void	push_swap_algo(t_array *ar)
{
	from_a_to_b(ar, 0, ar->nbr_chunck / 2 + 2);
	bring_num_above(ar, "min", 'a');
	while (ar->size_stack_b)
	{
		bring_num_above(ar, "max", 'b');
		make_move(1, "pa", ar);
	}
}

void	main_process(t_array *ar)
{
	if (check_sorted(ar))
		return ;
	if (ar->size_stack_a == 3)
		sort_3(ar);
	else if (ar->size_stack_a == 5)
		sort_5(ar);
	else
		push_swap_algo(ar);
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
	main_process(*array);
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
		main_process(array);
		error_handling(array, 0, 0);
	}
	return (0);
}
