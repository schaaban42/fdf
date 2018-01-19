/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:09:00 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/16 11:59:02 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int		gnl_add(t_line **remain, int fd, char *str)
{
	t_line		*new;

	if ((new = (t_line*)malloc(sizeof(t_line))) == NULL)
		return (0);
	new->content = str;
	new->fd = fd;
	new->next = NULL;
	if (*remain == NULL)
	{
		(*remain) = new;
		return (1);
	}
	if (new != NULL)
	{
		new->next = *remain;
		*remain = new;
	}
	return (1);
}

static t_line	*gnl_remain(t_line **remain, int fd)
{
	t_line		*cpy;

	cpy = (*remain);
	while (cpy != NULL)
	{
		if (cpy->fd == fd)
		{
			return (cpy);
		}
		cpy = cpy->next;
	}
	if (gnl_add(remain, fd, NULL) == 0)
		return (NULL);
	return (*remain);
}

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
			if ((line = ft_strnew(i)) == NULL ||
				(*remain = ft_strdup(str + i + 1)) == NULL)
				return (NULL);
			if (ft_strlen(*remain) == 0)
			{
				free(*remain);
				*remain = NULL;
			}
			line = ft_strncpy(line, str, i);
			return (line);
		}
	}
	if ((line = ft_strdup(str)) == NULL)
		return (NULL);
	return (line);
}

static int		gnl_read(char **line, t_line **remain, int fd, char *buff)
{
	char	*to_add;
	char	*prev_line;
	char	*prev_buff;
	int		end;

	end = 0;
	if ((prev_buff = ft_strdup(buff)) == NULL)
		return (1);
	if (gnl_remain(remain, fd)->content != NULL)
	{
		free(gnl_remain(remain, fd)->content);
		gnl_remain(remain, fd)->content = NULL;
	}
	to_add = gnl_split(prev_buff, &(gnl_remain(remain, fd)->content), &end);
	free(prev_buff);
	prev_line = *line;
	if ((*line = ft_strjoin(prev_line, to_add)) == NULL)
		return (1);
	if (to_add != NULL)
		free(to_add);
	if (prev_line != NULL)
		free(prev_line);
	return (end);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*remain;
	char			*buff;
	int				bytes_read;
	int				end;

	end = 0;
	bytes_read = 0;
	if (line == NULL || fd < 0 || (buff = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	*line = NULL;
	if (gnl_remain(&remain, fd)->content != NULL)
		end = gnl_read(line, &remain, fd, gnl_remain(&remain, fd)->content);
	while (!end && (bytes_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		end = gnl_read(line, &remain, fd, buff);
		ft_strclr(buff);
	}
	free(buff);
	if ((bytes_read == 0 && *line == NULL) || bytes_read < 0)
		return ((bytes_read < 0) ? -1 : 0);
	return (1);
}
