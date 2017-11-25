/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:19:22 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/28 11:36:23 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_findsize(char const *s, char c)
{
	int oldsize;
	int newsize;
	int i;

	i = 0;
	oldsize = ft_strlen((char *)s);
	newsize = oldsize;
	while ((i < oldsize) && s[i])
	{
		if (s[i] == c)
			newsize--;
		i++;
	}
	return (i);
}

static char		**ft_splitem(char const *s, char c, char **retstr)
{
	int i;
	int start;
	int index;

	index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			retstr[index] = ft_strsub(s, start, i - start);
			index++;
			retstr[index] = NULL;
		}
	}
	retstr[index] = 0;
	return (retstr);
}

char			**ft_strsplit(char const *s, char c)
{
	char **retstr;

	if (s == NULL)
		return (NULL);
	if (!(retstr = (char**)malloc(sizeof(char *) * (ft_findsize(s, c) + 1))))
		return (NULL);
	ft_bzero(retstr, ft_findsize(s, c) + 1);
	return (ft_splitem(s, c, retstr));
}
