/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:33:18 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/07 20:27:21 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

static void 	ui_general(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 20, 0xFFFFFF,
		"~~~~ FdF Manual ~~~~");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 40, 0xFFFFFF,
		"/* General *\\");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 55, 0xFFFFFF,
		"Reset all : 'R'");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 70, 0xFFFFFF,
		"Switch perpective : 'P'");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 85, 0xFFFFFF,
		"Fill/empty frames : 'F'");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 100, 0xFFFFFF,
		"Switch ui : 'H'");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 115, 0xFFFFFF,
		"Hide/show colors : 'C'");
}

static void		ui_camera(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 135, 0xFFFFFF,
		"/* Camera *\\");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 150, 0xFFFFFF,
		"Move : 'Arrows'");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 165, 0xFFFFFF,
		"Zoom : '+' and '-'");
}

static void		ui_scaling(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 185, 0xFFFFFF,
		"/* Scaling *\\");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 200, 0xFFFFFF,
		"X axis : 'D' (+) and 'A' (-)");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 215, 0xFFFFFF,
		"Y axis : 'W' (+) and 'S' (-)");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 230, 0xFFFFFF,
		"Z axis : 'X' (+) and 'Z' (-)");
}

static void		ui_perspective(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 250, 0xFFFFFF,
		"/* Perspective *\\");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 265, 0xFFFFFF,
		"Par. depth : 'E' (+) and 'Q' (-)");
	mlx_string_put(fdf->mlx_core, fdf->mlx_win, 20, 280, 0xFFFFFF,
		"Iso. depth : 'E' (+) and 'Q' (-)");
}

void		draw_ui(t_fdf *fdf)
{
	ui_general(fdf);
	ui_camera(fdf);
	ui_scaling(fdf);
	ui_perspective(fdf);
}
