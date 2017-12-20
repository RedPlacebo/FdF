/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:38:28 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/11 13:47:19 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		verify_basic(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		write(1, "usage: fdf [filename]\n", 23);
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error opening file\n", 20);
		exit(0);
	}
	if (-1 == read(fd, NULL, 0))
	{
		write(1, "Couldn't read file\n", 20);
		exit(0);
	}
	if (0 == read(fd, NULL, 1))
	{
		write(1, "Empty file\n", 11);
		exit(0);
	}
	close(fd);
}

void			start_data(t_data *data)
{
	data->dim.x = -1;
	data->dim.y = -1;
	data->dim.z = 0;
	data->dim.color = 0x00FFFFFF;
	data->theta_z = 0;
	data->theta_x = 0;
	data->theta_y = 0;
	data->trans_z = 0;
	data->trans_x = 100;
	data->trans_y = 100;
	data->scale_z = 20;
	data->scale_x = 20;
	data->scale_y = 20;
	data->spin_z = 0;
	data->spin_x = 0;
	data->spin_y = 0;
}

void			start_info(t_info *info, t_pos **map_o, t_pos **map_t,
		t_data *data)
{
	info->mlx = NULL;
	info->win = NULL;
	info->map_o = map_o;
	info->map_t = map_t;
	info->dim = &data->dim;
	info->data = data;
	return ;
}

int				main(int argc, char **argv)
{
	t_info	info;
	t_pos	*map_o;
	t_pos	*map_t;
	t_data	data;

	verify_basic(argc, argv);
	start_info(&info, &map_o, &map_t, &data);
	start_data(&data);
	if (init_map(&info, argv[1]) != 1)
	{
		write(1, "Could not read map\n", 19);
		exit(0);
	}
	start_drawing(&info);
	return (0);
}
