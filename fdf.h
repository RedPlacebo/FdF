#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libft/libft.h"


typedef		struct
{
	double		x;
	double		y;
	double		z;
}			t_position;

typedef			struct
{
	void		**mlx;
	void		**win;
	int			*scale;
	t_position	*center;
	t_position	*dim;
	t_position	**map;
	t_position	**map_o;
	int			theta_z;
	int			theta_y;
	int			theta_x;
	int			z_scale;
	int			spin;
	int			spin2;
	int			spin3;
}				t_info;

int			init_map(t_position **map, t_position **map_o, 
char 		*filename, t_position *dim);
void		start_drawing(t_position *map, t_position *map_o, t_position *dim);
int			my_key_funct(int keycode, t_info *info);
int			my_loop_hook(t_info *info);
void		set_scale(t_info *info, t_position **map, t_position **map_o);
void		draw_line(void *mlx, void *win, t_position p1, t_position p2, t_position center);
void		draw_all(void *mlx, void *win, t_position *map, t_position *dim, t_position center, t_info *info);
void    rotate_z_right(t_info *info, t_position **map, t_position **map_o, double theta);
void    rotate_x_right(t_info *info, t_position **map, t_position **map_o, double theta);
void    rotate_y_right(t_info *info, t_position **map, t_position **map_o, double theta);

#endif
