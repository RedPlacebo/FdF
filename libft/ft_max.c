/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 12:21:22 by ikarishe          #+#    #+#             */
/*   Updated: 2017/10/02 15:25:27 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, unsigned int len)
{
	int res;
	int length;

	res = -2147483648;
	length = len - 1;
	if (len == 0)
		return (0);
	while (length >= 0)
	{
		if (tab[length] > res)
			res = tab[length];
		length--;
	}
	return (res);
}
