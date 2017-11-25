/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:45:00 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/28 11:48:15 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;
	int					i;
	int					j;

	res = 0;
	sign = 1;
	i = 0;
	j = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	(str[i] == '-') ? (sign = -1) : (1);
	((str[i] == '-') || (str[i] == '+')) ? i++ : (1);
	while (str[i] == '0')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = (res * 10) + ((int)str[i] - '0');
		i++;
		j++;
	}
	if (j > 19 || res >= 9223372036854775808uLL)
		return ((sign == 1) ? -1 : 0);
	return (int)(res * sign);
}
