/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaaban <schaaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:31:42 by schaaban          #+#    #+#             */
/*   Updated: 2018/02/14 16:10:20 by schaaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 768
# define WIN_TITLE "~ FdF ~"
# define COLOR_MIN 0xFFFF00
# define COLOR_ZERO 0x0088FF
# define COLOR_MAX 0xFF1AFF

typedef struct	s_fdf
{
	void	*mlx_core;
	void	*mlx_win;
	int		**map;
	int		map_width;
	int		map_height;
	int		map_origin[2];
	double	map_scale[6];
	double	map_const[2];
	int		level_min;
	int		level_max;
	int		projection;
	int		fill;
	int		ui;
	int		color;
	int		fd;
}				t_fdf;

int				str_is_valid(char *str);

void			fdf_reset(t_fdf *fdf);
t_fdf			*fdf_init(int argc, char *file_name);

int				key_pressed(int keycode, void *param);

void			parse_file(t_fdf *fdf);

int				color_gradient(int cs, int ce, double value);
void			put_pixel(int x, int y, int color, t_fdf *fdf);
void			draw_line(int coords[4], t_fdf *fdf);

int				get_real_x(int x, int y, int z, t_fdf *fdf);
int				get_real_y(int x, int y, int z, t_fdf *fdf);
void			get_min_max_map(t_fdf *fdf);
int				get_real_color(int alt, t_fdf *fdf);
void			draw_map(t_fdf *fdf);

void			draw_map_h(t_fdf *fdf, int coords[6]);
void			draw_map_v(t_fdf *fdf, int coords[6]);
void			draw_map_f(t_fdf *fdf, int coords[6]);

void			draw_ui(t_fdf *fdf);

void			exit_fdf(t_fdf *fdf);
void			error_handler(int error, t_fdf *fdf);

#endif
