/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:17:20 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/25 15:39:37 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	char *s1;
	char *s2;

	s1 = (char *)str1;
	s2 = (char *)str2;
	while (n > 0)
	{
		*s1 = *s2;
		if (*s2 == (char)c)
			return ((void *)(s1 + 1));
		s1++;
		s2++;
		n--;
	}
	return (NULL);
}
