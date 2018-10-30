/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 21:43:04 by khou              #+#    #+#             */
/*   Updated: 2018/09/22 16:35:21 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_byte *temp;

	temp = (t_byte *)s;
	while (n--)
		if (*(temp++) == (t_byte)c)
			return (void *)(temp - 1);
	return (NULL);
}
