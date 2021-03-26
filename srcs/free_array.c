/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:04:04 by ymanzi            #+#    #+#             */
/*   Updated: 2021/03/26 10:04:08 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(t_array *arr)
{
	free(arr->stack_a);
	free(arr->stack_b);
	free(arr->full_sorted);
	free(arr->chunck);
	free(arr);
	arr = 0;
}
