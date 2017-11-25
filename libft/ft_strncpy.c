/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:19:26 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/25 15:41:27 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	strlen;
	size_t	i;

	i = 0;
	strlen = ft_strlen((char *)s2);
	while (i < n)
	{
		if (i > strlen)
			s1[i] = '\0';
		else
			s1[i] = s2[i];
		i++;
	}
	return (s1);
}
