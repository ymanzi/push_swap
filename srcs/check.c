/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:02:11 by ymanzi            #+#    #+#             */
/*   Updated: 2021/03/26 10:02:28 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_double(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str1;
	char	*str2;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (argv[i][0] == '+')
				str1 = argv[i] + 1;
			else
				str1 = argv[i];
			if (argv[j][0] == '+')
				str2 = argv[j] + 1;
			else
				str2 = argv[j];
			if (!strncmp(str1, str2, 12))
				return (0);
		}
	}
	return (1);
}

int		check_int_min_max(char *str)
{
	if (((str[0] == '+' || str[0] == '-') && ft_strlen(str + 1) < 10)
		|| ft_strlen(str) < 10)
		return (1);
	if (((str[0] == '+' || str[0] == '-') && ft_strlen(str + 1) > 10)
		|| ft_strlen(str) > 11)
		return (0);
	if ((str[0] == '+' && ft_strncmp("2147483647", str + 1, 12) < 0)
		|| (str[0] == '-' && ft_strncmp("2147483648", str + 1, 12) < 0)
		|| (ft_isdigit(str[0]) && ft_strncmp("2147483647", str, 12) < 0))
		return (0);
	return (1);
}

int		check_argv(int argc, char **argv)
{
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_is_all_digit(argv[i]))
			return (0);
		if (!check_int_min_max(argv[i]))
			return (0);
	}
	if (!check_double(argc, argv))
		return (0);
	return (1);
}

int		check_read(char *operation)
{
	int	len;

	len = ft_strlen(operation);
	if (len == 2 && (!ft_strncmp(operation, "sa", 4)
			|| !ft_strncmp(operation, "sb", 4)
			|| !ft_strncmp(operation, "ss", 4)
			|| !ft_strncmp(operation, "pa", 4)
			|| !ft_strncmp(operation, "pb", 4)
			|| !ft_strncmp(operation, "ra", 4)
			|| !ft_strncmp(operation, "rb", 4)
			|| !ft_strncmp(operation, "rr", 4)))
		return (1);
	else if (len == 3 && (!ft_strncmp(operation, "rra", 4)
			|| !ft_strncmp(operation, "rrb", 4)
			|| !ft_strncmp(operation, "rrr", 4)))
		return (1);
	else
		return (0);
}
