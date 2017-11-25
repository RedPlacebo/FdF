/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrerr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:18:13 by ikarishe          #+#    #+#             */
/*   Updated: 2017/10/02 14:21:52 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void		ft_putcharerr(char c)
{
	write(2, &c, 1);
}

void			ft_putstrerr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putcharerr(str[i]);
		i++;
	}
}
