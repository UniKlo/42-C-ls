/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 20:43:15 by khou              #+#    #+#             */
/*   Updated: 2018/09/22 16:35:55 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*clr(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	return ((char*)str);
}

int			ft_atoi(const char *str)
{
	int					isneg;
	long long			nbr;

	nbr = 0;
	isneg = 0;
	str = clr(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isneg++;
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	if (isneg)
		return (-nbr);
	return (nbr);
}
