/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:32:59 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/26 13:04:37 by schaaban         ###   ########.fr       */
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
		fdf->map ? free(fdf->map) : 0;
	}
	fdf ? ft_memdel((void**)&fdf) : 0;
	exit(0);
}

void		error_handler(int error, t_fdf *fdf)
{
	if (error == 0)
		ft_putendl("usage: fdf file");
	else if (error == 1)
		ft_putendl("error: initialization failed");
	else if (error == 2)
		ft_putendl("error: unable to open file");
	else if (error == 4)
		ft_putendl("error: unable to close file");
	else
	{
		if (error == 3)
			ft_putendl("error: file is not valid");
		if (error == 5)
			ft_putendl("error: mem-allocation failed");
		if (close(fdf->fd) != 0)
			ft_putendl("error: unable to close file");
	}
	exit_fdf(fdf);
}