/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:46:51 by khou              #+#    #+#             */
/*   Updated: 2018/09/22 16:35:23 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	num_len(int n)
{
	int		c;

	c = (n < 0) ? 2 : 1;
	while (n && (n /= 10))
		c++;
	return (c);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		neg;
	int		index;
	int		len;

	index = 0;
	len = num_len(n) - 1;
	ret = ft_strnew(num_len(n));
	if (!ret)
		return (0);
	neg = (n < 0) ? 1 : 0;
	while (n)
	{
		ret[len--] = (n % 10 > 0) ? (n % 10 + '0') : (n % 10 * (-1) + '0');
		n /= 10;
	}
	if (neg)
		ret[index++] = '-';
	if (ret[0] == 0)
		ret[0] = '0';
	return (ret);
}
