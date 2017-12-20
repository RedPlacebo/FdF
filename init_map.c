/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:18:41 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/20 13:15:18 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		count_numbers(char *buf)
{
	int		i;
	int		num;
	char	last;

	i = 0;
	num = 0;
	last = buf[i];
	while (i < (int)ft_strlen(buf))
	{
		if (((buf[i] >= '0') && (buf[i] <= '9')) || buf[i] == '-')
		{
			num++;
			while (((buf[i] >= '0') && (buf[i] <= '9')) || buf[i] == '-')
			{
				i++;
				if ((last == '-') && (buf[i] == '-'))
				{
					write(1, "double negative err\n", 20);
					exit(0);
				}
			}
		}
		i++;
	}
	return (num);
}

int		get_dimensions(char *filename, t_pos *dim)
{
	int		fd;
	int		x;
	int		y;
	char	*buf;

	x = 0;
	y = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &buf) != 0)
	{
		x = count_numbers(buf);
		if (dim->x == -1)
			dim->x = x;
		if (dim->x != x)
		{
			write(1, "Dim->x error\n", 13);
			exit(0);
		}
		y++;
		free(buf);
	}
	dim->x = x;
	dim->y = y;
	close(fd);
	return (1);
}

int		get_z(char *buf, int *j)
{
	int		i;
	char	num_buf[11];

	i = 0;
	while (((buf[i + *j] >= '0') && (buf[i + *j] <= '9')) || buf[i + *j] == '-')
	{
		num_buf[i] = buf[i + *j];
		i++;
	}
	if (ft_strlen(num_buf) > 9)
	{
		write(1, "Huge number detected\n", 21);
		exit(0);
	}
	num_buf[i] = '\0';
	*j = *j + i - 1;
	return (ft_atoi(num_buf));
}

/*
**	MOVED TO parseline.c because... norms... left here for reference
** void	parseline(t_pos **map, char *buf, int y, int *pos)
**{
**	int x;
**	int j;
**
**	x = 0;
**	j = 0;
**	while (buf[j] != '\0')
**	{
**		if ((buf[j] != ' ') && (buf[j] != '\n') &&
**				(buf[j] >= '9') && (buf[j] <= '0'))
**		{
**			write(1, "Invalid characters in map file\n", 31);
**			exit(0);
**		}
**		if (buf[j] == ' ')
**		{
**			j++;
**			continue;
**		}
**		(*map)[*pos].x = x;
**		(*map)[*pos].y = y;
**		(*map)[*pos].z = get_z(buf, &j);
**		if ((*map)[*pos].z < 0)
**			(*map)[*pos].color = 0x00000000 - (*map)[*pos].z * 7000;
**		else
**			(*map)[*pos].color = 0x00FFFFFF - (*map)[*pos].z * 7000;
**		x++;
**		j++;
**		*pos = *pos + 1;
**	}
**}
*/

int		fill_map(t_pos **map, char *filename)
{
	int		fd;
	int		y;
	char	*buf;
	int		pos;

	y = 0;
	pos = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &buf) > 0)
	{
		parseline(map, buf, y, &pos);
		y++;
	}
	close(fd);
	return (1);
}

int		init_map(t_info *info, char *filename)
{
	get_dimensions(filename, info->dim);
	*info->map_o = (t_pos*)malloc(sizeof(t_pos) * info->dim->x *
			info->dim->y + sizeof(t_pos*) * info->dim->x * info->dim->y);
	*info->map_t = (t_pos*)malloc(sizeof(t_pos) * info->dim->x *
			info->dim->y + sizeof(t_pos*) * info->dim->x * info->dim->y);
	fill_map(info->map_o, filename);
	fill_map(info->map_t, filename);
	return (1);
}
