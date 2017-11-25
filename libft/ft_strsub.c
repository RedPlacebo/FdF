/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 10:48:21 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/25 15:34:19 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*retstr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(retstr = (char*)malloc(sizeof(*retstr) * (len + 1))))
		return (NULL);
	while (s[start] && i < len)
	{
		retstr[i] = s[start];
		start++;
		i++;
	}
	retstr[i] = '\0';
	return (retstr);
}
