/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 22:27:26 by khou              #+#    #+#             */
/*   Updated: 2018/07/12 08:44:10 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	x;

	x = -1;
	while (++x < n)
		if (((t_byte *)s1)[x] != ((t_byte *)s2)[x])
			return (((t_byte *)s1)[x] - ((t_byte *)s2)[x]);
	return (0);
}
