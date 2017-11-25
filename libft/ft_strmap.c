/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 10:24:31 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/25 15:33:09 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((str = ft_memalloc(ft_strlen((char*)s) + 1)) == 0)
		return (NULL);
	while (*s)
	{
		str[i++] = f(*s);
		s++;
	}
	return (str);
}
