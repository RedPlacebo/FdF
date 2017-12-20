/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 12:29:30 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/04 16:33:54 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_list	*get_fd(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static void		read_tmp(const int fd, void **main_buffer)
{
	char	sub_buffer[BUFF_SIZE + 1];
	int		bytes_read;
	char	*where_i_was_pointing;

	bytes_read = 1;
	while (bytes_read > 0 && ft_strchr(*main_buffer, '\n') == NULL)
	{
		bytes_read = read(fd, &sub_buffer, BUFF_SIZE);
		if (bytes_read < 0)
			return ;
		sub_buffer[bytes_read] = '\0';
		where_i_was_pointing = *main_buffer;
		*main_buffer = ft_strjoin(*main_buffer, (const char *)sub_buffer);
		free(where_i_was_pointing);
		ft_bzero(sub_buffer, BUFF_SIZE);
	}
	return ;
}

int				get_next_line(const int fd, char **line)
{
	char			*cut_ptr;
	char			*tmp;
	static t_list	*file;
	t_list			*curr;

	if (fd < 0 || line == NULL || (-1 == read(fd, NULL, 0)))
		return (-1);
	curr = get_fd(&file, fd);
	if (!curr->content)
		curr->content = ft_strnew(BUFF_SIZE);
	read_tmp(curr->content_size, &curr->content);
	if ((cut_ptr = ft_strchr(curr->content, '\n')) != NULL)
	{
		*cut_ptr = '\0';
		*line = ft_strdup(curr->content);
		tmp = ft_strdup(cut_ptr + 1);
		free(curr->content);
		curr->content = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	*line = ft_strdup(curr->content);
	free(curr->content);
	curr->content = NULL;
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
