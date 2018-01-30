/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:28:50 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/29 21:55:50 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int				main(int argc, char **argv)
{
	t_fdf	*fdf;
	
	fdf = fdf_init(argc, argv[1]);
	draw_map(fdf);
	mlx_key_hook(fdf->mlx_win, key_pressed, (void*)fdf);
	mlx_mouse_hook(fdf->mlx_win, mouse_pressed, (void*)fdf);
	mlx_loop(fdf->mlx_core);
	return (0);
}
