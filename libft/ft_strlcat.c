/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:12:15 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/26 12:20:37 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dlen;

	i = 0;
	if (size == 0)
		return (ft_strlen(dst));
	while (dst[i] && i < size)
		i++;
	dlen = i;
	while (src[i - dlen] && i < size - 1)
	{
		dst[i] = src[i - dlen];
		i++;
	}
	if (dlen < size)
		dst[i] = '\0';
	return (dlen + ft_strlen((char*)src));
}
