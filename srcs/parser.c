/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:55:13 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/29 22:11:31 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>


static int		parser_size_check(char **lines, t_fdf *fdf)
{
	char	**columns;
	int		last_width;
	int		i;

	i = 0;
	last_width = 0;
	columns = NULL;
	while (lines[i] != NULL)
	{
		if (!(columns = ft_strsplit(lines[i], ' ')))
		{
			columns ? ft_a2ddel((void***)&columns) : 0;
			return (-1);
		}
		fdf->map_width = ft_a2dlen((const void**)columns);
		columns ? ft_a2ddel((void***)&columns) : 0;
		if (i != 0 && fdf->map_width != last_width)
			return (0);
		last_width = fdf->map_width;
		i++;
	}
	fdf->map_height = i;
	if (fdf->map_width < 2 || fdf->map_height < 2)
		return (0);
	return (1);
}

static int		parser_fill_line(char *line, int map_i, t_fdf *fdf)
{
	char	**columns;
	int		i;

	i = -1;
	if (!(columns = ft_strsplit(line, ' ')))
		return (-1);
	while (columns[++i] != NULL)
	{
		if (!(ft_str_isdigit(columns[i])))
		{
			ft_a2ddel((void***)&columns);
			return (0);
		}
		fdf->map[map_i][i] = ft_atoi(columns[i]);
	}
	ft_a2ddel((void***)&columns);
	return (1);
}

static int		parser_fill_map(char **lines, t_fdf *fdf)
{
	int		i;
	int		line_res;

	i = -1;
	while (lines[++i] != NULL)
	{
		if (!(fdf->map[i] = (int*)malloc(sizeof(int) * fdf->map_width)))
			return (-1);
		if ((line_res = parser_fill_line(lines[i], i, fdf)) < 1)
			return (line_res);
	}
	fdf->map[i] = NULL;
	return (1);
}

static int		parser_getmap(char *file_str, t_fdf *fdf)
{
	char	**lines;
	int		parse_res;

	if (!(lines = ft_strsplit(file_str, '\n')))
		return (-1);
	if ((parse_res = parser_size_check(lines, fdf)) < 1)
	{
		lines ? ft_a2ddel((void***)&lines) : 0;
		return (parse_res);
	}
	if (!(fdf->map = (int**)malloc(sizeof(int*) *
		(ft_a2dlen((const void**)lines) + 1))))
	{
		lines ? ft_a2ddel((void***)&lines) : 0;
		return (-1);
	}
	if ((parse_res = parser_fill_map(lines, fdf)) < 1)
	{
		lines ? ft_a2ddel((void***)&lines) : 0;
		return (parse_res);
	}
	lines ? ft_a2ddel((void***)&lines) : 0;
	return (1);
}

void			parse_file(t_fdf *fdf)
{
	char	*file_str;
	char	*file_line;
	int		parse_result;
	int 	ret;

	file_str = NULL;
	while ((ret = get_next_line(fdf->fd, &file_line)) > 0)
	{
		if (!(file_str = ft_strjoin_free(file_str, file_line)))
		{
			file_line ? ft_memdel((void**)&file_line) : 0;
			error_handler(5, fdf);
		}
		if (!(file_str = ft_strjoin_free(file_str, "\n")))
		{
			file_line ? ft_memdel((void**)&file_line) : 0;
			error_handler(5, fdf);
		}
		file_line ? ft_memdel((void**)&file_line) : 0;
	}
	(ret < 0) ? error_handler(6, fdf) : 0;
	!file_str ? error_handler(5, fdf) : 0;
	parse_result = parser_getmap(file_str, fdf);
	file_str ? ft_memdel((void**)&file_str) : 0;
	(parse_result < 1) ? error_handler((parse_result == -1) ? 5 : 3, fdf) : 0;
}
