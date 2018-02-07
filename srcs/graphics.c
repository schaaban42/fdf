/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 23:46:33 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/07 17:37:26 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void			put_pixel(int x, int y, int color, t_fdf *fdf)
{
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
		mlx_pixel_put(fdf->mlx_core, fdf->mlx_win, x, y, color);
}

int		color_gradient(int cs, int ce, double value)
{
	int		c1[3];
	int		c2[3];
	int		cf[3];

	c1[0] = cs & 0xFF0000;
	c1[1] = cs & 0x00FF00;
	c1[2] = cs & 0x0000FF;
	c2[0] = ce & 0xFF0000;
	c2[1] = ce & 0x00FF00;
	c2[2] = ce & 0x0000FF;
	cf[0] = (c1[0] + (int)((double)(c2[0] - c1[0]) * value)) & 0xFF0000;
	cf[1] = (c1[1] + (int)((double)(c2[1] - c1[1]) * value)) & 0x00FF00;
	cf[2] = (c1[2] + (int)((double)(c2[2] - c1[2]) * value)) & 0x0000FF;
	return (cf[0] | cf[1] | cf[2]);
}

static void		first_case(int ar_i[9], t_fdf *fdf)
{
	int		i;

	i = 0;
	ar_i[6] = ar_i[2]/2;
	while (i < ar_i[2])
	{
		ar_i[0] += ar_i[4];
		ar_i[6] += ar_i[3];
		if (ar_i[6] > ar_i[2])
		{
			ar_i[6] -= ar_i[2];
			ar_i[1] += ar_i[5];
		}
		put_pixel(ar_i[0], ar_i[1], color_gradient(ar_i[7], ar_i[8],
			((double)i / (double)ar_i[2])), fdf);
		i++;
	}
}

static void		second_case(int ar_i[9], t_fdf *fdf)
{
	int		i;

	i = 0;
	ar_i[6] = ar_i[3] / 2;
	while (i < ar_i[3])
	{
		ar_i[1] += ar_i[5];
		ar_i[6] += ar_i[2];
		if (ar_i[6] > ar_i[3])
		{
			ar_i[6] -= ar_i[3];
			ar_i[0] += ar_i[4];
		}
		put_pixel(ar_i[0], ar_i[1], color_gradient(ar_i[7], ar_i[8],
			((double)i / (double)ar_i[3])), fdf);
		i++;
	}
}

void			draw_line(int cc[6], t_fdf *fdf)
{
	int ar_i[9];

	ar_i[2] = abs(cc[2] - cc[0]);
	ar_i[3] = abs(cc[3] - cc[1]);
	ar_i[4] = (cc[0] < cc[2]) ? 1 : -1;
	ar_i[5] = (cc[1] < cc[3]) ? 1 : -1;
	ar_i[0] = cc[0];
	ar_i[1] = cc[1];
	ar_i[7] = cc[4];
	ar_i[8] = cc[5];
	(ar_i[2] > ar_i[3]) ? first_case(ar_i, fdf) : second_case(ar_i, fdf);
	put_pixel(cc[0], cc[1], cc[4], fdf);
	put_pixel(cc[2], cc[3], cc[5], fdf);
}
