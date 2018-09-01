/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 22:31:12 by khou              #+#    #+#             */
/*   Updated: 2018/07/19 10:31:30 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) - 1;
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (i >= 0)
		if (s[i--] == (char)c)
			return ((char *)s + i + 1);
	return (NULL);
}
