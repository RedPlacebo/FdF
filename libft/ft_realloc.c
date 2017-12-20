/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 16:13:35 by ikarishe          #+#    #+#             */
/*   Updated: 2017/12/05 16:14:42 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_realloc(char *str, int size)
{
	char	*temp;
	int		i;

	temp = str;
	str = (char *)malloc(sizeof(char) * size);
	i = 0;
	while (temp[i])
	{
		str[i] = temp[i];
		i++;
	}
	free(temp);
	return (str);
}
