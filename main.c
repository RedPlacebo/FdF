/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:27:01 by ikarishe          #+#    #+#             */
/*   Updated: 2017/11/25 13:34:01 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 1. verify that the number of arguments = 1
 * 2. verify that the file can be opened and read
 * 3. read file into an *map of struct(x, y, z) -> (init_map.c)
 * 4. pass *map to the function that does the math and drawing (core.c)
 *
 * We hold 2 copies of the map, the first copy, map_o consists of the original
 * x,y,z positions as they appear in the fdf file that is read. Every frame
 * that is drawn starts with map_o and transforms it into map which is drawn.
 *
 * Bresenham's line algorithm (draw_line.c)
 * 
 *
 */

#include "fdf.h"
#include <stdio.h>


static int	verify_file(char *filename)
{
	int fd;
	char ghost;    

	if (!(fd = open(filename, O_RDONLY)))
    {
        write(1, "Error opening file\n", 20);
        return (-1);
    }
    if (-1 == read(fd, &ghost, 0))
    {
        write(1, "Couldn't read file\n", 20);
        return (-1);
    }
	close(fd);
	return (1);
}

int 		main(int argc, char **argv)
{
	t_position	*map;
	t_position  *map_o;
	t_position  dim;

	map = NULL;
	map_o = NULL;
	if (argc != 2)
	{
		write(1, "usage: fdf [filename]\n", 23);
		return (-1);
	}
	if (verify_file(argv[1]) != 1)
	{
		write(1, "File fucked up\n", 15);
		return (-1);
	}
	if (init_map(&map, &map_o, argv[1], &dim) != 1)
	{
		write(1, "Map fucked up\n", 14);
		return (-1);
	}
	start_drawing(map, map_o, &dim);
	return (0);
}
