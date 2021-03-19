#include "push_swap.h"

void	make_operation_on_array(t_array *array, char *operation)
{
	if (!ft_strncmp(operation, "sa", 4))
		sa(array);
	else if (!ft_strncmp(operation, "sb", 4))
		sb(array);
	else if (!ft_strncmp(operation, "ss", 4))
		ss(array);
	else if (!ft_strncmp(operation, "pa", 4))
		pa(array);
	else if (!ft_strncmp(operation, "pb", 4))
		pb(array);
	else if (!ft_strncmp(operation, "ra", 4))
		ra(array);
	else if (!ft_strncmp(operation, "rb", 4))
		rb(array);
	else if (!ft_strncmp(operation, "rr", 4))
		rr(array);
	else if (!ft_strncmp(operation, "rra", 4))
		rra(array);
	else if (!ft_strncmp(operation, "rrb", 4))
		rrb(array);
	else if (!ft_strncmp(operation, "rrr", 4))
		rrr(array);
}

int		error_handling(t_array *array, char *line)
{
	if (array)
		free_array(array);
	if (line)
		free(line);
	write(2, "Error\n", 6);
	return (0);
}

int		main(int argc, char **argv)
{
	t_array	*array;
	char	*line;
	int		ret;

	array = 0;
	line = 0;
	if (argc == 1)
		return (0);
	if (!check_argv(argc, argv)
	|| !(array = argv_to_array(argc, argv)))
		return (error_handling(array, line));
	while ((ret = get_next_line(0, &line) > 0))
	{
		if (!check_read(line))
			return (error_handling(array, line));
		make_operation_on_array(array, line);
		free(line);
	}
	// CHECK IF SORTED
	// If sorted():
	// 	write(1, "OK\n", 3);
	// else
	// 	write(1, "OK\n", 3);
	return (0);
}
