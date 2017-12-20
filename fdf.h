/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:58:11 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/11 13:23:19 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include "minilibx2/mlx.h"

/*
**	Holds an x, y, z position and a color
*/
typedef struct	s_pos
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_pos;

/*
** Holds the data discribing the current state of the world
** dimensions, rotations, translation ect.
*/
typedef struct	s_data
{
	t_pos		dim;
	int			theta_z;
	int			theta_x;
	int			theta_y;
	int			trans_z;
	int			trans_x;
	int			trans_y;
	int			scale_z;
	int			scale_x;
	int			scale_y;
	int			spin_z;
	int			spin_x;
	int			spin_y;
}				t_data;

/*
**	Holds pointers to all the variables that frequently need getting passed
*/
typedef struct	s_info
{
	void		*mlx;
	void		*win;
	t_pos		**map_o;
	t_pos		**map_t;
	t_pos		*dim;
	t_data		*data;
}				t_info;

/*
** 	Holds pointers to 2 points,
** 	the color value of the current pixel to be drawn
**	a multiplier representing the distance between first and current pixel
**  the amounts to increment (r, g, b) values for each pixel
**	and the distance between the two points to be drawn
*/
typedef struct	s_line
{
	t_pos		p1;
	t_pos		p2;
	int			p_color;
	int			mult;
	double		r_step;
	double		g_step;
	double		b_step;
	double		distance;
}				t_line;

/*
** Holds a bunch of variables to make apply_rotation pass norms
*/
typedef struct	s_rot
{
	double		s;
	double		c;
	int			centx;
	int			centy;
	int			xnew;
	int			ynew;
	int			znew;
}				t_rot;

int				init_map(t_info	*info, char *filename);
void			start_drawing(t_info *info);
void			draw_line(t_info *info, t_pos *p1, t_pos *p2);
int				my_key_funct(int keycode, t_info *info);
int				my_loop_hook(t_info *info);
int				my_mouse_hook(t_info *info);
void			set_scale(t_info *info, t_pos **map_o, t_pos **map_t);
void			scale_z(t_info *info, int scale);
void			scale_x(t_info *info, int scale);
void			scale_y(t_info *info, int scale);
void			translate_world(t_info *info, t_pos **map_t);
void			trans_x(t_info *info, int scale);
void			trans_y(t_info *info, int scale);
void			rotate_world(t_info *info, t_pos **map_t);
void			rotate_z(int keycode, t_info *info);
void			rotate_x(int keycode, t_info *info);
void			rotate_y(int keycode, t_info *info);
void			apply_z_rotation(t_info *info, t_pos **map_t);
void			apply_x_rotation(t_info *info, t_pos **map_t);
void			apply_y_rotation(t_info *info, t_pos **map_t);
void			parseline(t_pos **map, char *buf, int y, int *pos);
int				get_z(char *buf, int *j);
void			draw_all(t_info *info);
int				pixel_color(t_line *line);
void			pixel_steps(t_line *line);

#endif
