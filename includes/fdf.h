/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:31:42 by schaaban          #+#    #+#             */
/*   Updated: 2018/01/30 21:26:01 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 960
# define WIN_TITLE "~ FdF ~"

typedef struct	s_fdf
{
	void	*mlx_core;
	void	*mlx_win;
	int		**map;
	int		map_width;
	int		map_height;
	int		map_origin_x;
	int		map_origin_y;
	double	map_scale_x;
	double	map_scale_y;
	double	map_depth;
	int		color_min;
	int		color_zero;
	int		color_max;
	int		level_min;
	int		level_max;
	int		fd;
}				t_fdf;

t_fdf			*fdf_init(int argc, char *file_name);

int				key_pressed(int keycode, void *param);
int				mouse_pressed(int button, int x, int y, void *param);

void			parse_file(t_fdf *fdf);

void			put_pixel(int x, int y, int color, t_fdf *fdf);
void			draw_line(int coords[4], t_fdf *fdf);

void			draw_map(t_fdf *fdf);

void			exit_fdf(t_fdf *fdf);
void			error_handler(int error, t_fdf *fdf);

#endif
