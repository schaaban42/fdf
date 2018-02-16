/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:23:51 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/14 11:30:06 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

void		draw_map_h(t_fdf *fdf, int coords[6])
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->map_height)
	{
		j = 0;
		while (++j < fdf->map_width)
		{
			coords[0] = get_real_x(j - 1, i, fdf->map[i][j - 1], fdf);
			coords[1] = get_real_y(j - 1, i, fdf->map[i][j - 1], fdf);
			coords[2] = get_real_x(j, i, fdf->map[i][j], fdf);
			coords[3] = get_real_y(j, i, fdf->map[i][j], fdf);
			coords[4] = (fdf->color) ?
				get_real_color(fdf->map[i][j - 1], fdf) : 0xFFFFFF;
			coords[5] = (fdf->color) ?
				get_real_color(fdf->map[i][j], fdf) : 0xFFFFFF;
			draw_line(coords, fdf);
		}
	}
}

void		draw_map_v(t_fdf *fdf, int coords[6])
{
	int		i;
	int		j;

	j = -1;
	while (++j < fdf->map_width)
	{
		i = 0;
		while (++i < fdf->map_height)
		{
			coords[0] = get_real_x(j, i - 1, fdf->map[i - 1][j], fdf);
			coords[1] = get_real_y(j, i - 1, fdf->map[i - 1][j], fdf);
			coords[2] = get_real_x(j, i, fdf->map[i][j], fdf);
			coords[3] = get_real_y(j, i, fdf->map[i][j], fdf);
			coords[4] = (fdf->color) ?
				get_real_color(fdf->map[i - 1][j], fdf) : 0xFFFFFF;
			coords[5] = (fdf->color) ?
				get_real_color(fdf->map[i][j], fdf) : 0xFFFFFF;
			draw_line(coords, fdf);
		}
	}
}

void		draw_map_f(t_fdf *fdf, int coords[6])
{
	int		i;
	int		j;

	i = 0;
	while (++i < fdf->map_height)
	{
		j = 0;
		while (++j < fdf->map_width)
		{
			coords[0] = get_real_x(j - 1, i, fdf->map[i][j - 1], fdf);
			coords[1] = get_real_y(j - 1, i, fdf->map[i][j - 1], fdf);
			coords[2] = get_real_x(j, i - 1, fdf->map[i - 1][j], fdf);
			coords[3] = get_real_y(j, i - 1, fdf->map[i - 1][j], fdf);
			coords[4] = (fdf->color) ?
				get_real_color(fdf->map[i][j - 1], fdf) : 0xFFFFFF;
			coords[5] = (fdf->color) ?
				get_real_color(fdf->map[i - 1][j], fdf) : 0xFFFFFF;
			draw_line(coords, fdf);
		}
	}
}
