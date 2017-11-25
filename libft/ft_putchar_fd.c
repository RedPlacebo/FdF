/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:57:50 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/28 11:53:38 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put(int c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putchar_fd(int c, int fd)
{
	if (c < 0x80)
	{
		ft_put(c, fd);
	}
	else if (c < 0x800)
	{
		ft_put((0xC0 | (c >> 6)), fd);
		ft_put((0x80 | (c & 0x3F)), fd);
	}
	else if (c < 0x10000)
	{
		ft_put((0xE0 | (c >> 12)), fd);
		ft_put((0x80 | ((c >> 6) & 0x3F)), fd);
		ft_put((0x80 | (c & 0x3F)), fd);
	}
	else if (c < 0x200000)
	{
		ft_put((0xF0 | (c >> 18)), fd);
		ft_put((0x80 | ((c >> 12) & 0x3F)), fd);
		ft_put((0x80 | ((c >> 6) & 0x3F)), fd);
		ft_put((0x80 | (c & 0x3F)), fd);
	}
}
