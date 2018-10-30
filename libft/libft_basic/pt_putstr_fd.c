/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:24:13 by khou              #+#    #+#             */
/*   Updated: 2018/09/22 16:35:21 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		pt_putstr_fd(char const *s, int fd, int len)
{
	static int	count;

	count = 0;
	while (*s && count < len)
	{
		write(fd, s++, 1);
		count++;
	}
	return (count);
}
