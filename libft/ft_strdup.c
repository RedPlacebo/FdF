/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:18:44 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/21 13:29:55 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *ret;

	ret = (char*)malloc(ft_strlen((char*)str) + 1);
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, (char*)str);
	return (ret);
}
