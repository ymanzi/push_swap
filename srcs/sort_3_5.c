/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:05:25 by ymanzi            #+#    #+#             */
/*   Updated: 2021/03/26 10:05:28 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_array *ar)
{
	int pos_min;
	int	pos_max;

	pos_min = move_from_top(ar, get_minmax(ar, 'a', "min"), 'a');
	pos_max = move_from_top(ar, get_minmax(ar, 'a', "max"), 'a');
	if (pos_min == 1 && pos_max == 2)
		make_move(1, "sa", ar);
	else if (pos_min == 2 && pos_max == 0)
	{
		make_move(1, "ra", ar);
		make_move(1, "sa", ar);
	}
	else if (pos_min == 1 && pos_max == 0)
		make_move(1, "ra", ar);
	else if (pos_min == 0 && pos_max == 1)
	{
		make_move(1, "sa", ar);
		make_move(1, "ra", ar);
	}
	else if (pos_min == 2 && pos_max == 1)
		make_move(1, "rra", ar);
}

void	sort_5(t_array *ar)
{
	bring_num_above(ar, "min", 'a');
	make_move(1, "pb", ar);
	bring_num_above(ar, "min", 'a');
	make_move(1, "pb", ar);
	sort_3(ar);
	make_move(1, "pa", ar);
	make_move(1, "pa", ar);
}
