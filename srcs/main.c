/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:28:50 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/14 16:10:26 by schaaban         ###   ########.fr       */
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
	mlx_hook(fdf->mlx_win, 2, 1L, key_pressed, (void*)fdf);
	mlx_loop(fdf->mlx_core);
	return (0);
}
