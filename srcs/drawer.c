/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:31:34 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/30 11:57:37 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

static int		get_real_x(int x, int z, t_fdf *fdf)
{
	return (fdf->map_origin_x -
		(((fdf->map_width - 1) * fdf->map_scale_x) / 2) +
		(x * fdf->map_scale_x) + (int)(fdf->map_scale_y * (double)z));
}

static int		get_real_y(int y, int z, t_fdf *fdf)
{
	return ((fdf->map_origin_y -
		(((fdf->map_height - 1) * fdf->map_scale_y) / 2) -
		(z * fdf->map_depth) + (int)((fdf->map_scale_y * 2) * (double)y)));
}

void			draw_map(t_fdf *fdf)
{
	int		i;
	int		j;
	
	i = -1;
	while (++i < fdf->map_height)
	{
		j = 0;
		while (++j < fdf->map_width)
		{
			draw_line(
				get_real_x(j - 1, i, fdf), 
				get_real_y(i, fdf->map[i][j - 1], fdf),
				get_real_x(j, i, fdf), 
				get_real_y(i, fdf->map[i][j], fdf), fdf);
		}
	}

	j = -1;
	while (++j < fdf->map_width)
	{
		i = 0;
		while (++i < fdf->map_height)
		{
			draw_line(
				get_real_x(j, i - 1, fdf), 
				get_real_y(i - 1, fdf->map[i - 1][j], fdf),
				get_real_x(j, i, fdf), 
				get_real_y(i, fdf->map[i][j], fdf), fdf);
		}
	}
	put_pixel(get_real_x(0, fdf->map[1 - 1][0], fdf), 
				get_real_y(1 - 1, fdf->map[1 - 1][0], fdf), 0x0000FF, fdf);
}
