/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 10:59:30 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/25 16:32:43 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		trim_start(int *nlen, char const *s)
{
	while (((s[*nlen - 1] == ' ') || (s[*nlen - 1] == '\n') ||
				(s[*nlen - 1] == '\t')) && (*nlen > 0))
		*nlen = *nlen - 1;
}

static int		trim_end(int *nlen, char const *s)
{
	int i;

	i = 0;
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t')) && (*nlen > 0))
	{
		*nlen = *nlen - 1;
		i++;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		nlen;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	nlen = ft_strlen((char*)s);
	i = 0;
	j = 0;
	trim_start(&nlen, s);
	i = trim_end(&nlen, s);
	if (!(str = (char*)malloc(sizeof(*str) * (nlen + 1))))
		return (NULL);
	while (nlen > 0)
	{
		str[j] = s[i];
		j++;
		i++;
		nlen--;
	}
	str[j] = '\0';
	return (str);
}
