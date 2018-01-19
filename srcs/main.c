/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:28:50 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/19 12:22:54 by schaaban         ###   ########.fr       */
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
	if (keycode == 53)
		exit(0);
	return (0);
}

int		error_handler(int error)
{
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
	int		fd;

	if (argc != 2)
		return (error_handler(0));
	if (!(fd = open(argv[1], O_RDONLY)))
		return (error_handler(1));
	if (!(mlx = mlx_win_init()))
		return (0);
	if (!parse_file(fd))
		return (0);
	if (close(fd) != 0)
		return (error_handler(3));
	mlx_key_hook(mlx->window, key_pressed, (void*)mlx);
	mlx_loop(mlx->core);
	return (0);
}
