/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:54:20 by ikarishe          #+#    #+#             */
/*   Updated: 2017/10/02 12:15:10 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putc(int c)
{
	write(1, &c, 1);
}

void			ft_putchar_uni(int c)
{
	if (c < 0x80)
	{
		ft_putc(c);
	}
	else if (c < 0x800)
	{
		ft_putc(0xC0 | (c >> 6));
		ft_putc(0x80 | (c & 0x3F));
	}
	else if (c < 0x10000)
	{
		ft_putc(0xE0 | (c >> 12));
		ft_putc(0x80 | ((c >> 6) & 0x3F));
		ft_putc(0x80 | (c & 0x3F));
	}
	else if (c < 0x200000)
	{
		ft_putc(0xF0 | (c >> 18));
		ft_putc(0x80 | ((c >> 12) & 0x3F));
		ft_putc(0x80 | ((c >> 6) & 0x3F));
		ft_putc(0x80 | (c & 0x3F));
	}
}
