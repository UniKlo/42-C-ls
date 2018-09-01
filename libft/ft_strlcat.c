/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:13:50 by khou              #+#    #+#             */
/*   Updated: 2018/07/18 19:56:55 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;

	s = 0;
	while (dst[s] && s < size)
		s++;
	if (size == s)
		return (size + ft_strlen(src));
	ft_strncat(&dst[s], src, size - s - 1);
	return (s + ft_strlen(src));
}
