#include "push_swap.h"

int		get_nbr_chunck(int size)
{
	if (size < 99)
		return (4);
	else if (size < 495)
		return (6);
	else
		return (11);
}

void	set_chunck(t_array *array)
{
	int	i;
	int	j;
	int	step;
	int	full_size;

	i = -1;
	j = -1;
	full_size = array->size_stack_a;
	array->nbr_chunck = get_nbr_chunck(full_size);
	step = full_size / array->nbr_chunck;
	while (++j < array->nbr_chunck)
		array->chunck[j] = j * step;
	array->chunck[j] = full_size + 1;
}

int		get_size_argv(char **tab)
{
	int	i;

	i = -1;
	while(tab[++i])
		;
	return (i);
}

t_array	*argv_to_array(int argc, char **argv)
{
	int		i;
	t_array	*ar;

	i = 0;
	if (!(ar = (t_array*)malloc(sizeof(t_array)))
	|| !(ar->stack_a = (int*)malloc(sizeof(int) * (argc - 1)))
	|| !(ar->full_sorted = (int*)malloc(sizeof(int) * (argc - 1)))
	|| !(ar->chunck = (int*)malloc(sizeof(int) * (argc - 1)))
	|| !(ar->stack_b = (int*)malloc(sizeof(int) * (argc - 1))))
	{
		write(1, "lol", 3);
		return (0);
	}
	ar->size_stack_a = argc - 1;
	ar->size_stack_b = 0;
	while (++i < argc)
	{
		ar->stack_a[argc - 1 - i] = ft_atoi(argv[i]);
		ar->full_sorted[argc - 1 - i] = ft_atoi(argv[i]);
	}
	quick_sort(ar->full_sorted, 0, argc - 2);
	set_chunck(ar);
	ar->indice_chunck = 0;
	return (ar);
}
