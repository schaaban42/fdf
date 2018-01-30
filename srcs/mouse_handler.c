/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:00:48 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/30 17:51:44 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"

int		mouse_pressed(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (button == 1)
	{
		fdf = fdf;
		x = x;
		y = y;
	}
	return (0);
}
