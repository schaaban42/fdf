/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:00:48 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/29 17:39:17 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

int		mouse_pressed(int button, int x, int y, void *param)
{
	static int xl, yl;
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (button == 1)
	{
		draw_line(xl, yl, x, y, fdf);
		xl = x;
		yl = y;
	}
	return (0);
}
