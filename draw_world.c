/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:43:31 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/20 13:40:05 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_world(t_info *info, t_pos **map_t)
{
	int i;
	int j;

	(void)map_t;
	i = 1;
	j = 0;
	while (j < (info->dim->x * info->dim->y) - 1)
	{
		if (j == (int)((info->dim->x) * i) - 1)
		{
			draw_line(info, &((*map_t)[j]), &((*map_t)[j + (int)info->dim->x]));
			j++;
			i++;
			continue;
		}
		draw_line(info, &((*map_t)[j]), &((*map_t)[j + 1]));
		if (j < (info->dim->x * info->dim->y - info->dim->x))
		{
			draw_line(info, &((*map_t)[j]), &((*map_t)[j + (int)info->dim->x]));
		}
		j++;
	}
}

void	draw_all(t_info *info)
{
	mlx_clear_window(info->mlx, info->win);
	set_scale(info, info->map_o, info->map_t);
	rotate_world(info, info->map_t);
	translate_world(info, info->map_t);
	draw_world(info, info->map_t);
}

void	start_drawing(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 1200, 800, "fdf");
	draw_all(info);
	mlx_key_hook(info->win, my_key_funct, info);
	mlx_loop_hook(info->mlx, my_loop_hook, info);
	mlx_mouse_hook(info->win, my_mouse_hook, info);
	mlx_loop(info->mlx);
}
