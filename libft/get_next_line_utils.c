/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:47:20 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/08 12:31:00 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin_(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 && s2 == 0)
		return (NULL);
	if (!(ptr = (char*)malloc(sizeof(*ptr) * (ft_strlen_(s1)
						+ ft_strlen_(s2) + 1))))
		return (NULL);
	while (*(s1 + i))
		ptr[j++] = *(s1 + i++);
	i = 0;
	while (*(s2 + i))
		ptr[j++] = *(s2 + i++);
	ptr[j] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}

char	*ft_substr_(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen_((char*)s) < start)
		len = 0;
	if (s == 0 || !(ptr = (char*)malloc(sizeof(*ptr) * (len + 1))))
		return (NULL);
	while (len-- > 0 && *(s + start + i))
	{
		ptr[i] = s[start + i];
		i++;
	}
	*(ptr + i) = '\0';
	return (ptr);
}

int		find_line(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	creat_str_nl(char *s1, char **tmp, char **line, int *ret)
{
	int	i;

	if (*ret != -1)
	{
		i = find_line(s1);
		if (i > 0)
		{
			*line = ft_substr_(s1, 0, i);
			*tmp = ft_substr_(s1, i + 1, ft_strlen_(s1) - i - 1);
		}
		else if (i < 0)
		{
			*line = ft_substr_(s1, 0, ft_strlen_(s1));
			*tmp = ft_substr_(s1, ft_strlen_(s1) + 2, 100);
		}
		else
		{
			*line = ft_substr_(s1, ft_strlen_(s1) + 2, 1);
			*tmp = ft_substr_(s1, 1, ft_strlen_(s1) - 1);
		}
		free(s1);
		s1 = NULL;
	}
	if (*line == NULL || *tmp == NULL)
		*ret = -1;
}
