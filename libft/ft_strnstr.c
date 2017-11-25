/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:17:14 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/26 12:15:52 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int i;
	int j;
	int tempn;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while ((haystack[i] != '\0') && n)
	{
		j = 0;
		tempn = n;
		while ((haystack[i + j] == needle[j]) && tempn)
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
			tempn--;
		}
		i++;
		n--;
	}
	return (0);
}
