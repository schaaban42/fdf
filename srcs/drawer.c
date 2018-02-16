/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:31:34 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/14 11:30:16 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>

int				get_real_x(int x, int y, int z, t_fdf *fdf)
{
	int		nx;

	nx = z;
	if (fdf->projection == 1)
	{
		nx = fdf->map_origin[0] - 
			(((fdf->map_width - 1) * fdf->map_scale[0] * fdf->map_scale[3]) -
			((fdf->map_height - 1) * fdf->map_scale[1] * fdf->map_scale[4])) / 2 +
			(x * fdf->map_scale[0] * fdf->map_scale[3]);
		return ((int)(nx - (y * fdf->map_scale[1] * fdf->map_scale[4])));
	}
	else
	{
		nx = fdf->map_origin[0] - 
			((fdf->map_width - 1) * fdf->map_scale[0] * fdf->map_scale[3] / 2) +
			(x * fdf->map_scale[0] * fdf->map_scale[3]) +
			((fdf->map_height - 1) * fdf->map_scale[1] *
			fdf->map_scale[4] * 0.5 * fdf->map_const[0]);
		return ((int)(nx - (fdf->map_const[0] *
			(y * fdf->map_scale[1] * fdf->map_scale[4]))));
	}
	return (0);
}

int				get_real_y(int x, int y, int z, t_fdf *fdf)
{
	int		ny;

	if (fdf->projection == 1)
	{
		ny = fdf->map_origin[1] - 
			(((fdf->map_width - 1) * fdf->map_scale[0] *
			fdf->map_scale[3] * fdf->map_const[1]) +
			((fdf->map_height - 1) * fdf->map_scale[1] *
			fdf->map_scale[4])) / 2 +
			(y * fdf->map_scale[1] * fdf->map_scale[4]);
		return ((int)(-(z * fdf->map_scale[2] *
			fdf->map_scale[5]) + fdf->map_const[1] * 
			(x * fdf->map_scale[0] * fdf->map_scale[3]) + ny));
	}
	else
	{
		ny = fdf->map_origin[1] - 
			((fdf->map_height - 1) *
			fdf->map_scale[1] * fdf->map_scale[4] / 2) +
			(y * fdf->map_scale[1] * fdf->map_scale[4]);
		return ((int)(ny - (1 * (z * fdf->map_scale[2] * fdf->map_scale[5]))));
	}
	return (0);
}

void			get_min_max_map(t_fdf *fdf)
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

int				get_real_color(int alt, t_fdf *fdf)
{
	if (alt == 0)
		return (COLOR_ZERO);
#ifdef COLOR_ZMIN
	else if (alt > 0)
		return (color_gradient(COLOR_ZMAX, COLOR_MAX,
			((double)alt / (double)fdf->level_max)));
#else
	else if (alt > 0)
		return (color_gradient(COLOR_ZERO, COLOR_MAX,
			((double)alt / (double)fdf->level_max)));
#endif
#ifdef COLOR_ZMAX
	else
		return (color_gradient(COLOR_ZMIN, COLOR_MIN,
			((double)alt / (double)fdf->level_min)));
#else
	else
		return (color_gradient(COLOR_ZERO, COLOR_MIN,
			((double)alt / (double)fdf->level_min)));
#endif
}

void			draw_map(t_fdf *fdf)
{
	int		coords[6];

	mlx_clear_window(fdf->mlx_core, fdf->mlx_win);
	get_min_max_map(fdf);
	draw_map_h(fdf, coords);
	draw_map_v(fdf, coords);
	if (fdf->fill)
		draw_map_f(fdf, coords);
	if (fdf->ui)
		draw_ui(fdf);
}
