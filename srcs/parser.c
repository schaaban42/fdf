/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:35:33 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/19 15:37:36 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

static char	**prs_lines_ok(char *str, int *tab_width)
{
	char	**lines;
	char	**line;
	int		i;
	int		j;

	i = -1;
	lines = ft_strsplit(str, '\n');
	while (lines[++i] != NULL)
	{
		j = -1;
		line = ft_strsplit(lines[i], ' ');
		while (line[++j] != NULL)
		{
	ft_printf("BONJOUR CA VA\n");
			if (j > 0 && (int)ft_strlen(line[j]) != *tab_width)
			{
				ft_a2ddel((void**)line);
				ft_a2ddel((void**)lines);
				return (NULL);
			}
			*tab_width = ft_strlen(line[j]);
		}
	}
	ft_a2ddel((void**)line);
	return (lines);
}

static int	**prs_getmap(char *str, int *tab_width)
{
	int		**map;
	char	**lines;
	char	**line_split;
	int		i;
	int		j;

	if (!(lines = prs_lines_ok(str, tab_width)))
		return (NULL);
	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * 
		(ft_a2dlen((const void**)lines) + 1))))
		return (NULL);
	while (lines[i] != NULL)
	{
		j = 0;
		line_split = ft_strsplit(lines[i], ' ');
		if (!(map[i] = (int*)malloc(sizeof(int) * (*tab_width))))
			return (NULL);
		while (j < (*tab_width))
		{
			map[i][j] = ft_atoi(line_split[j]);
			j++;
		}
	}
	return (map);
}

int			**parse_file(int fd, int *tab_width)
{
	int		**map;
	char	*str;
	char	*line;

	str = NULL;
	while (get_next_line(fd, &line))
	{
		str = ft_strjoin_free(str, line);
		str = ft_strjoin_free(str, "\n");
		ft_memdel((void**)&line);
	}
	if (!str)
		return (NULL);
	map = prs_getmap(str, tab_width);
	ft_memdel((void**)&str);
	return (map);
}
