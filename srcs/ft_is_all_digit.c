/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:04:13 by ymanzi            #+#    #+#             */
/*   Updated: 2021/03/26 10:04:16 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_all_digit(char *str)
{
	int		i;
	int		len;
	char	*verif;

	i = -1;
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (!len)
		return (0);
	if ((str[0] == '-' || str[0] == '+') && len > 1)
		verif = str + 1;
	else
		verif = str;
	while (verif[++i])
	{
		if (!ft_isdigit(verif[i]))
			return (0);
	}
	return (1);
}
