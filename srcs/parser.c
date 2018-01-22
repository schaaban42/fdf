/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:35:33 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/22 17:19:10 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdlib.h>

static int	**prs_getmap(char *str, int *map_width)
{
	str = "binberoigj";
	*map_width = 9;
	map_width = (int*)str;
	str = (char*)map_width;
	return ((int**)67);
}

int			**parse_file(int fd, int *map_width)
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
	ft_printf("Str : %s", str);
	map = prs_getmap(str, map_width);
	ft_memdel((void**)&str);
	return (map);
}
