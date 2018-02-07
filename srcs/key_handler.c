/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:21:10 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/07 19:48:46 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

static void		map_move(int dir, t_fdf *fdf)
{
	if (dir == 65361)
		fdf->map_origin[0] += 20;
	else if (dir == 65363)
		fdf->map_origin[0] -= 20;
	else if (dir == 65362)
		fdf->map_origin[1] += 20;
	else if (dir == 65364)
		fdf->map_origin[1] -= 20;
	else
		return ;
	draw_map(fdf);
}

static void		map_zoom(int zoom, t_fdf *fdf)
{
	if (zoom == 45)
	{
		fdf->map_scale[0] *= 0.8;
		fdf->map_scale[1] *= 0.8;
		fdf->map_scale[2] *= 0.8;
	}
	else if (zoom == 61)
	{
		fdf->map_scale[0] *= (1 / 0.8);
		fdf->map_scale[1] *= (1 / 0.8);
		fdf->map_scale[2] *= (1 / 0.8);
	}
	else
		return ;
	draw_map(fdf);
}

static void		map_scale(int scale, t_fdf *fdf)
{
	if (scale == 100)
		fdf->map_scale[3] += 0.2;
	else if (scale == 97)
		fdf->map_scale[3] -= (fdf->map_scale[3] - 0.2 < 0) ? 0 : 0.2;
	else if (scale == 119)
		fdf->map_scale[4] += 0.2;
	else if (scale == 115)
		fdf->map_scale[4] -= (fdf->map_scale[4] - 0.2 < 0) ? 0 : 0.2;
	else if (scale == 120)
		fdf->map_scale[5] += 0.2;
	else if (scale == 122)
		fdf->map_scale[5] -= 0.2;
	else if (scale == 101)
		fdf->map_const[fdf->projection] += 0.2;
	else if (scale == 113)
		fdf->map_const[fdf->projection] -= 0.2;
	else
		return ;
	draw_map(fdf);
}

static void		map_other(int other, t_fdf *fdf)
{
	if (other == 112)
		fdf->projection = (fdf->projection == 1) ? 0 : 1;
	else if (other == 114)
		fdf_reset(fdf);
	else if (other == 102)
		fdf->fill = (fdf->fill == 1) ? 0 : 1;
	else if (other == 104)
		fdf->ui = (fdf->ui == 1) ? 0 : 1;
	else if (other == 99)
		fdf->color = (fdf->color == 1) ? 0 : 1;
	else
		return ;
	draw_map(fdf);
}

int		key_pressed(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (keycode == 65307)
		exit_fdf(fdf);
	map_move(keycode, fdf);
	map_zoom(keycode, fdf);
	map_scale(keycode, fdf);
	map_other(keycode, fdf);
	ft_printf("%d\n", keycode);
	return (0);
}
