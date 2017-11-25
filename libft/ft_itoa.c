/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:25:46 by ikarishe          #+#    #+#             */
/*   Updated: 2017/09/25 16:15:27 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		getlen(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void		strflip(char *str, int len)
{
	int		i;
	char	tmp;

	i = 0;
	if (str[0] == '-')
		i++;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		len--;
		i++;
	}
}

static void		special(int n, char *str)
{
	if (n == 0)
		str[0] = 0 + '0';
	else if (n == -2147483648)
		ft_strcpy(str, "-2147483648");
}

static void		fill(int n, int i, char *str)
{
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
}

char			*ft_itoa(int n)
{
	int		i;
	int		length;
	char	*str;

	i = 0;
	length = getlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	str[length] = '\0';
	if (n == 0 || n == -2147483648)
	{
		special(n, str);
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	fill(n, i, str);
	strflip(str, length - 1);
	return (str);
}
