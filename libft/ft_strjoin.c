/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 10:54:52 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/25 15:35:44 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char*)s1) + ft_strlen((char *)s2);
	if (!(str = (char*)malloc((sizeof(*str) * (size + 1)))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, (char*)s2);
	return (str);
}
