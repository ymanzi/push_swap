/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:04:32 by ymanzi            #+#    #+#             */
/*   Updated: 2021/03/26 10:04:34 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		one_arg(t_array **array, char *str)
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
		return (error_handling(*array, 0, 1));
	}
	free_double_tab(tab_arg);
	return (1);
}

void	end(t_array *array, char *line)
{
	if (check_sorted(array))
		write(1, "OK\n", 3);
	else
		write(1, "K0\n", 3);
	error_handling(array, line, 0);
}

int		first_part(int argc, char **argv, char *line, int ret)
{
	t_array	*array;

	array = NULL;
	if (argc == 2 && just_digit_and_space(argv[1]))
	{
		if (!one_arg(&array, argv[1]))
			return (0);
	}
	else
	{
		if (!check_argv(argc, argv) || !(array = argv_to_array(argc, argv)))
			return (error_handling(array, line, 1));
	}
	while ((ret = get_next_line(0, &line) > 0) && ft_strlen(line))
	{
		if (!check_read(line))
			return (error_handling(array, line, 1));
		make_operation_on_array(array, line);
		free(line);
	}
	end(array, line);
	return (1);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		ret;

	line = 0;
	ret = 0;
	if (argc == 1)
		return (0);
	return (first_part(argc, argv, line, ret));
}
