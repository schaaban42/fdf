/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:52:36 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/25 12:28:12 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char		*gnl_split(char *str, char **remain, int *end)
{
	char	*line;
	int		i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
		{
			*end = 1;
			if (!(line = ft_strnew(i)))
				return (NULL);
			if (!(*remain = ft_strdup(str + i + 1)))
			{
				line ? free(line) : 0;
				return (NULL);
			}
			if (ft_strlen(*remain) == 0)
				ft_memdel((void**)remain);
			line = ft_strncpy(line, str, i);
			return (line);
		}
	}
	return (line = ft_strdup(str));
}

static int		gnl_read(char **line, char **remain, char *buff)
{
	char	*to_add;
	char	*prev_buff;
	int		end;

	end = 0;
	prev_buff = ft_strdup(buff);
	ft_memdel((void**)remain);
	if (!prev_buff)
		return (-1);
	to_add = gnl_split(prev_buff, remain, &end);
	free(prev_buff);
	if (!to_add)
		return (-1);
	*line = ft_strjoin_free(*line, to_add);
	to_add ? free(to_add) : 0;
	return (!(*line) ? -1 : end);
}

int				get_next_line(const int fd, char **line)
{
	static char		*remain[MAX_FD] = {NULL};
	char			buff[BUFF_SIZE];
	int				bytes_read;
	int				end;

	end = 0;
	bytes_read = 0;
	if (!line || fd < 0 || fd >= MAX_FD)
		return (-1);
	*line = NULL;
	ft_bzero(buff, BUFF_SIZE + 1);
	if (remain[fd] != NULL)
		end = gnl_read(line, &(remain[fd]), remain[fd]);
	while (!end && (bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		end = gnl_read(line, &(remain[fd]), buff);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	if ((end < 0 || bytes_read < 0) || (bytes_read == 0 && !*line))
	{
		*line ? ft_strdel(line) : 0;
		remain[fd] ? ft_strdel(&(remain[fd])) : 0;
		return ((end < 0 || bytes_read < 0) ? -1 : 0);
	}
	return (1);
}
