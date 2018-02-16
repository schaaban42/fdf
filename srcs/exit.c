/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:32:59 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/15 13:21:50 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>

void		exit_fdf(t_fdf *fdf)
{
	if (fdf)
	{
		fdf->mlx_core ? ft_memdel((void**)&fdf->mlx_core) : 0;
		fdf->mlx_win ? ft_memdel((void**)&fdf->mlx_win) : 0;
		fdf->map ? ft_a2ddel((void***)&fdf->map) : 0;
	}
	fdf ? ft_memdel((void**)&fdf) : 0;
	exit(0);
}

void		error_handler(int error, t_fdf *fdf)
{
	if (error == 0)
		ft_putendl_fd("usage: fdf file", 2);
	else if (error == 1)
		ft_putendl_fd("error: initialization failed", 2);
	else if (error == 2)
		ft_putendl_fd("error: unable to open file", 2);
	else if (error == 4)
		ft_putendl_fd("error: unable to close file", 2);
	else
	{
		if (error == 3)
			ft_putendl_fd("error: file is not valid", 2);
		else if (error == 5)
			ft_putendl_fd("error: mem-allocation failed", 2);
		else if (error == 6)
			ft_putendl_fd("error: not a valid file", 2);
		if (close(fdf->fd) != 0)
			ft_putendl_fd("error: unable to close file", 2);
	}
	exit_fdf(fdf);
}
