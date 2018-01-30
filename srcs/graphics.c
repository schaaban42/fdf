/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 23:46:33 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/29 17:50:07 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void			put_pixel(int x, int y, int color, t_fdf *fdf)
{
	mlx_pixel_put(fdf->mlx_core, fdf->mlx_win, x, y, color);
}

static void		first_case(int ar_i[7], t_fdf *fdf)
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
		put_pixel(ar_i[0], ar_i[1], 0xFFFFFF, fdf);
		i++;
	}
}

static void		second_case(int ar_i[7], t_fdf *fdf)
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
		put_pixel(ar_i[0], ar_i[1], 0xFFFFFF, fdf);
		i++;
	}
}

void			draw_line(int x1, int y1, int x2, int y2, t_fdf *fdf)
{
	int ar_i[7];

	ar_i[2] = abs(x2 - x1);
	ar_i[3] = abs(y2 - y1);
	ar_i[4] = (x1 < x2) ? 1 : -1;
	ar_i[5] = (y1 < y2) ? 1 : -1;
	ar_i[0] = x1;
	ar_i[1] = y1;
	(ar_i[2] > ar_i[3]) ? first_case(ar_i, fdf) : second_case(ar_i, fdf);
	put_pixel(x1, y1, 0xFFFFFF, fdf);
	put_pixel(x2, y2, 0xFFFFFF, fdf);
}
