/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:05:52 by ymanzi            #+#    #+#             */
/*   Updated: 2021/03/26 10:05:54 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements).
*/

void	sa(t_array *array)
{
	int array_size;

	if (array->size_stack_a > 1)
	{
		array_size = array->size_stack_a;
		ft_swap(&array->stack_a[array_size - 1],
			&array->stack_a[array_size - 2]);
	}
}

/*
** swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements).
*/

void	sb(t_array *array)
{
	int array_size;

	if (array->size_stack_b > 1)
	{
		array_size = array->size_stack_b;
		ft_swap(&array->stack_b[array_size - 1],
			&array->stack_b[array_size - 2]);
	}
}

/*
** swap the first 2 elements at the top of stack b and stack a.
**	Do nothing if there is only one or no elements).
*/

void	ss(t_array *array)
{
	if (array->size_stack_a > 1)
		sa(array);
	if (array->size_stack_b > 1)
		sb(array);
}
