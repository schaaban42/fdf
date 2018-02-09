/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:06:38 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/09 16:34:17 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void			fdf_reset(t_fdf *fdf)
{
	if (!fdf)
		return ;
	fdf->map_origin[0] = WIN_WIDTH / 2;
	fdf->map_origin[1] = WIN_HEIGHT / 2;
	fdf->map_scale[0] = 16;
	fdf->map_scale[1] = 16;
	fdf->map_scale[2] = 2;
	fdf->map_scale[3] = 1;
	fdf->map_scale[4] = 1;
	fdf->map_scale[5] = 1;
	fdf->map_const[0] = 0;
	fdf->map_const[1] = 0.6;
	fdf->projection = 1;
	fdf->fill = 0;
	fdf->ui = 1;
	fdf->color = 1;
}

static void		init_struct(t_fdf **fdf)
{
	(*fdf)->mlx_core = NULL;
	(*fdf)->mlx_win = NULL;
	(*fdf)->map = NULL;
}

static t_fdf	*init_create_win(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		error_handler(1, NULL);
	init_struct(&fdf);
	if (!(fdf->mlx_core = mlx_init()))
		error_handler(1, fdf);
	if (!(fdf->mlx_win =
		mlx_new_window(fdf->mlx_core, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE)))
		error_handler(1, fdf);
	fdf_reset(fdf);
	return (fdf);
}

t_fdf			*fdf_init(int argc, char *file_name)
{
	t_fdf	*fdf;

	if (argc != 2)
		error_handler(0, NULL);
	if (!(fdf = init_create_win()))
		error_handler(1, fdf);
	if ((fdf->fd = open(file_name, O_RDONLY)) < 0)
		error_handler(2, fdf);
	parse_file(fdf);
	if (close(fdf->fd) != 0)
		error_handler(4, fdf);
	return (fdf);
}
