/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 09:37:31 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/08 12:28:33 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*tmp[OPEN_MAX] = {0};
	int				ret;

	ret = 1;
	if (!line || fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (!tmp[fd])
	{
		if (!(tmp[fd] = (char*)malloc(sizeof(char))))
			return (-1);
		tmp[fd][0] = '\0';
	}
	while (find_line(tmp[fd]) == -1 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp[fd] = ft_strjoin_(tmp[fd], buf)))
			return (free_fct(line, &tmp[fd], -1));
	}
	creat_str_nl(tmp[fd], &tmp[fd], line, &ret);
	if (ret == -1)
		return (free_fct(line, &tmp[fd], -1));
	return ((ret > 0 ? 1 : free_fct(line, &tmp[fd], 0)));
}

int	free_fct(char **line, char **tmp, int ret)
{
	if (*line != NULL && ret != 0)
	{
		free(*line);
		*line = NULL;
	}
	if (*tmp != NULL)
	{
		free(*tmp);
		*tmp = NULL;
	}
	return (ret);
}
