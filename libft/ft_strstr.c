/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 22:59:56 by khou              #+#    #+#             */
/*   Updated: 2018/07/15 11:18:48 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;

	i = 0;
	if (!(*to_find))
		return ((char *)str);
	while (*str)
	{
		while (str[i] == to_find[i])
		{
			if (to_find[i + 1] == '\0')
				return ((char *)str);
			i++;
		}
		i = 0;
		str++;
	}
	return (0);
}
