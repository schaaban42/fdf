/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:28:50 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/22 17:15:44 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int		key_pressed(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (keycode == 65307)
		exit(0);
	mlx_pixel_put(mlx->core, mlx->window, 100, 100, 0x0000FF);
	return (0);
}

int		error_handler(int error)
{
	if (error == -2)
		ft_printf("error: could not initialize\n");
	if (error == -1)
		ft_printf("error: m-allocation failed\n");
	if (error == 0)
		ft_printf("usage: fdf file\n");
	if (error == 1)
		ft_printf("error: could not open file\n");
	if (error == 2)
		ft_printf("error: not a valid file\n");
	if (error == 3)
		ft_printf("error: could not close file\n");
	return (0);
}

t_mlx	*mlx_win_init(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->core = mlx_init();
	mlx->window = mlx_new_window(mlx->core, WIN_WIDTH, WIN_HEIGHT, "~ FdF ~");
	return (mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		**map;
	int		map_width;
	int		fd;

	if (argc != 2)
		return (error_handler(0));
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error_handler(1));
	if (!(mlx = mlx_win_init()) || !(map = parse_file(fd, &map_width)))
		return (error_handler(-2));
	if (close(fd) != 0)
		return (error_handler(3));
	mlx_pixel_put(mlx->core, mlx->window, 250, 250, 0xFF0000);
	mlx_key_hook(mlx->window, key_pressed, (void*)mlx);
	mlx_loop(mlx->core);
	return (0);
}
