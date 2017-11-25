/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:58:38 by ikarishe          #+#    #+#             */
/*   Updated: 2017/11/25 15:50:24 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include "minilibx/mlx.h"

void	draw_all(void *mlx, void *win, t_position *map, t_position *dim, t_position center, t_info *info)
{
	int i;
	int j;

	i = 1;
	j = 0;
	mlx_clear_window(mlx, win);
	(void)info;
	(void)map;
	(void)dim;
	(void)center;
	set_scale(info, info->map, info->map_o);
	rotate_z_right(info, info->map, info->map_o, (info->theta_z * M_PI / 180));
	rotate_x_right(info, info->map, info->map_o, (info->theta_x * M_PI / 180));
	rotate_y_right(info, info->map, info->map_o, (info->theta_y * M_PI / 180));
	
	while (j < (dim->x * dim->y) - 1)
	{
		if (j == ((dim->x * i) - 1))
		{
			draw_line(mlx, win, map[j], map[j + (int)dim->x], center);
			j++;
			i++;
			continue;
		}
		draw_line(mlx, win, map[j], map[j + 1], center);
		if (j < (dim->x * dim->y - dim->x))
			draw_line(mlx, win, map[j], map[j + (int)dim->x], center);
		j++;
	}
	mlx_string_put(mlx, win, 100, 100 , 0x00FFFFFF,  "Booyah");
}

void	set_center(t_position *center, int x, int y)
{
	center->x = x;
	center->y = y;
}

void	start_drawing(t_position *map, t_position *map_o, t_position *dim)
{
	void 	*mlx;
	void 	*win;
	int 	scale;
	t_info	info;
	t_position center;

	set_center(&center, 300, 250);
	scale = 4;

	info.mlx = &mlx;
	info.win = &win;
	info.scale = &scale;
	info.center = &center;
	info.dim = dim;
	info.map = &map;
	info.map_o = &map_o;
	info.theta_z = 0;
	info.theta_y = 0;
	info.theta_x = 0;
	info.z_scale = 1;
	info.spin = 0;
	info.spin2 = 0;
	info.spin3 = 0;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 1200, 800, "fdf");

	draw_all(mlx, win, map, dim, center, &info);	

	mlx_key_hook(win, my_key_funct, &info);
	mlx_loop_hook(mlx, my_loop_hook, &info);
//	mlx_mouse_hook(mlx, my_mouse_hook, &info);
	mlx_loop(mlx);

	return ;
}
