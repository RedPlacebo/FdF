/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:57:49 by ikarishe          #+#    #+#             */
/*   Updated: 2017/11/25 13:39:27 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*open file... again...
 * read through the file to find out the number of lines, and columns
 * verify that all lines/colums are of the same size - NOT DONE
 * malloc the proper amount of space for t_position *map and *map_o;
 * read each line and set the (x, y, z) positions of each map element
 * do it again for map_o
 * 
 * if it encounters any characters that are not numbers, spaces, or \n
 * 	exits;
 *	not sure what the intended display for map - pyrmaid.fdf is supposed to be
 *
 * */



#include "fdf.h"
#include <stdio.h>

int count_numbers(char *buf)
{
	int i;
	int num;

	i = 0;
	num = 0;

	while (buf[i] != '\0')
	{
		if (((buf[i] >= '0') && (buf[i] <= '9')) || buf[i] == '-')
		{
			num++;
			while(((buf[i] >= '0') && (buf[i] <= '9')) || buf[i] == '-')
				i++;
		}
		i++;
	}
	return (num);
}

int	get_dimensions(char *filename, t_position *dim)
{
	int fd;
	int x;
	int y;
	char *buf;

	x = 0;
	y = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &buf) != 0)
	{	
		x = count_numbers(buf);
		//length verification goes here... somehow
		y++;
	}
	dim->x = x;
	dim->y = y;
	close(fd);
	return (1);
}

int		get_z(char *buf, int *j)
{
	int i;
	char num_buf[11];

	i = 0;
	while(((buf[i + *j] >= '0') && (buf[i + *j] <= '9')) || buf[i + *j] == '-')
	{
		num_buf[i] = buf[i + *j];
		i++;
	}
	num_buf[i] = '\0';
	*j = *j + i - 1;
	return (ft_atoi(num_buf));
}

void parseline(t_position **map, char *buf, int y, int *pos)
{
	int x;
	int j;

	x = 0;
	j = 0;
	while(buf[j] != '\0')
	{
		if((buf[j] != ' ') && (buf[j] != '\n') && (buf[j] >= '9') && (buf[j] <= '0'))
		{
			write(1, "Invalid characters in map file\n", 31);
			exit (0);
		}
		if(buf[j] == ' ')
		{
			j++;
			continue;
		}
		(*map)[*pos].x = x;
		(*map)[*pos].y = y;
		(*map)[*pos].z = get_z(buf, &j);
		x++;
		j++;
		*pos = *pos + 1;
	}
}

int	fill_map(t_position **map, char *filename)
{
	int fd;
	int y;
	char *buf;
	int pos;

	y = 0;
	pos = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &buf) != 0)
	{
		parseline(map, buf, y, &pos);	
		y++;
	}
	close(fd);
	return (1);
}

int	init_map(t_position **map, t_position **map_o, 
		char *filename, t_position *dim)
{
	if(!map || !filename || !map_o || !dim)
		return (0);
	get_dimensions(filename, dim);
	*map = (t_position*)malloc(sizeof(double) * 3 * dim->x * dim->y + 
			sizeof(t_position*) * dim->x * dim->y);
	*map_o = (t_position*)malloc(sizeof(double) * 3 * dim->x *dim->y +
			sizeof(t_position*) * dim->x * dim->y);
	fill_map(map, filename);
	fill_map(map_o, filename);
	return (1);
}
