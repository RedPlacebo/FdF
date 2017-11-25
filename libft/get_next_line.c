/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 12:29:30 by ikarishe          #+#    #+#             */
/*   Updated: 2017/10/31 12:59:48 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* check that the file directory, and **line are valid
 * check that there's stuff to read in the file
 * 
 * Initialize a buffer
 * Keep reading BUFF_SIZE characters into temp
 * 		until you hit a \n or read 0/-1 bytes
 * use strjoin to stick what you read onto the end
 * the buffer. strjoin auto-mallocs.
 *
 * now that buffer either has a \n or doesn't,
 * 		if it has a \n
 * 		find where that \n is, and overwrite it with a \0
 * 		now we can strdup it into *line. Its still holding characters
 * 		so make the buffer pointer point to where that \n was + 1
 * 		exit;
 * if it doesn't have a \n
 *		you're at the end of the file. The buffer might hold stuff if the
 *		file doesn't end in a \n. Dump whats in the buffer into *line.
 *		clear the buffer.
 *		exit;
 * */

#include "libft.h"
#include "get_next_line.h"

static int	read_tmp(const int fd, char **buf)
{
	char 	str1[BUFF_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(*buf, '\n') == NULL)
	{
		bytes_read = read(fd, &str1, BUFF_SIZE);
		if (bytes_read < 0)
			return (-1);
		str1[bytes_read] = '\0';
		*buf = ft_strjoin(*buf, (const char *)str1);
		ft_bzero(str1, BUFF_SIZE);
	}
	return (bytes_read);
}

int		get_next_line(const int fd, char **line)
{
	static char 	*buffer;
	char	*str;
	int 	len;

	if (fd < 0 || line == NULL || (-1 == read(fd, buffer, 0)))
		return (-1);
	if (!buffer)
		buffer = ft_strnew(BUFF_SIZE);
	len = read_tmp(fd, &buffer);
	if ((str = ft_strchr(buffer, '\n')) != NULL)
	{
		str[0] = '\0';
		*line = ft_strdup(buffer);
		buffer = str + 1;
		return (1);
	}
	*line = ft_strdup(buffer);
	buffer = NULL;	
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
