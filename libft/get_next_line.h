/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymanzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:10:06 by ymanzi            #+#    #+#             */
/*   Updated: 2019/11/08 12:33:43 by ymanzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#	ifndef BUFFER_SIZE
#	define BUFFER_SIZE 1000
#	endif

#	ifndef OPEN_MAX
#	define OPEN_MAX 100
#	endif

#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int			get_next_line(int fd, char **line);
size_t		ft_strlen_(char *s);
char		*ft_strjoin_(char *s1, char *s2);
char		*ft_substr_(char *s, unsigned int start, size_t len);
int			find_line(char *str);
void		creat_str_nl(char *s1, char **tmp, char **line, int *ret);
int			free_fct(char **line, char **tmp, int ret);

#	endif
