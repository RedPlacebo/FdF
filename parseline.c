/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:48:04 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/20 11:49:41 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	checkchar(char c)
{
	if ((c != ' ') && (c != '\n') && (c != '-') && !((c >= '0') && (c <= '9')))
	{
		write(1, "Invalid characters in map file\n", 31);
		exit(0);
	}
}

void	above_color(t_pos **map, int *pos)
{
	(*map)[*pos].color = 0x00FFFFFF - (*map)[*pos].z * 7000;
	(*map)[*pos].color = ((*map)[*pos].color & 0x00FFFF00);
}

void	below_color(t_pos **map, int *pos)
{
	(*map)[*pos].color = 0x00000000 + (*map)[*pos].z * 7000;
	(*map)[*pos].color = ((*map)[*pos].color & 0x0000FFFF);
}

void	parseline(t_pos **map, char *buf, int y, int *pos)
{
	int x;
	int j;

	x = 0;
	j = 0;
	while (buf[j] != '\0')
	{
		checkchar(buf[j]);
		if (buf[j] == ' ')
		{
			j++;
			continue;
		}
		(*map)[*pos].x = x;
		(*map)[*pos].y = y;
		(*map)[*pos].z = get_z(buf, &j) / 1;
		if ((*map)[*pos].z < 0)
			below_color(map, pos);
		else
			above_color(map, pos);
		x++;
		j++;
		*pos = *pos + 1;
	}
}
