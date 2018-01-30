/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:31:34 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/30 21:20:17 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include <stdio.h>

static int		get_real_x(int x, int z, t_fdf *fdf)
{
	return ((int)(fdf->map_origin_x -
		(((fdf->map_width - 1) * fdf->map_scale_x) / 2) +
		(x * fdf->map_scale_x) + (int)(fdf->map_scale_y * (double)z)));
}

static int		get_real_y(int y, int z, t_fdf *fdf)
{
	return ((int)(fdf->map_origin_y -
		(((fdf->map_height - 1) * fdf->map_scale_y) / 2) -
		(z * fdf->map_depth) + (int)((fdf->map_scale_y * 3) * (double)y)));
}

static void		get_min_max_map(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	fdf->level_min = 0;
	fdf->level_max = 0;
	while (++i < fdf->map_height)
	{
		j = -1;
		while (++j < fdf->map_width)
		{
			if (fdf->map[i][j] > fdf->level_max)
				fdf->level_max = fdf->map[i][j];
			if (fdf->map[i][j] < fdf->level_min)
				fdf->level_min = fdf->map[i][j];
		}
	}
}

static int		get_real_color(int alt, t_fdf *fdf)
{
	if (alt == 0)
		return (fdf->color_zero);
	else if (alt > 0)
		return (fdf->color_zero + (fdf->color_max - fdf->color_zero) * ((double)alt / (double)fdf->level_max));
	else
		return (fdf->color_zero + (fdf->color_min - fdf->color_zero) * (((double)alt / (double)fdf->level_min)));
}

void			draw_map(t_fdf *fdf)
{
	int		i;
	int		j;
	int		coords[6];
	
	get_min_max_map(fdf);
	i = -1;
	while (++i < fdf->map_height)
	{
		j = 0;
		while (++j < fdf->map_width)
		{
			coords[0] = get_real_x(j - 1, i, fdf);
			coords[1] = get_real_y(i, fdf->map[i][j - 1], fdf);
			coords[2] = get_real_x(j, i, fdf);
			coords[3] = get_real_y(i, fdf->map[i][j], fdf);
			coords[4] = get_real_color(fdf->map[i][j - 1], fdf);
			coords[5] = get_real_color(fdf->map[i][j], fdf);
			draw_line(coords, fdf);
		}
	}

	j = -1;
	while (++j < fdf->map_width)
	{
		i = 0;
		while (++i < fdf->map_height)
		{
			coords[0] = get_real_x(j, i - 1, fdf);
			coords[1] = get_real_y(i - 1, fdf->map[i - 1][j], fdf);
			coords[2] = get_real_x(j, i, fdf);
			coords[3] = get_real_y(i, fdf->map[i][j], fdf);
			coords[4] = get_real_color(fdf->map[i - 1][j], fdf);
			coords[5] = get_real_color(fdf->map[i][j], fdf);
		//printf("%d %d %d %d\n", fdf->map[i - 1][j], get_real_color(fdf->map[i - 1][j], fdf), fdf->map[i][j],
		//get_real_color(fdf->map[i][j], fdf));
			draw_line(coords, fdf);
		}
	}
}
