/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 14:33:05 by khou              #+#    #+#             */
/*   Updated: 2018/09/27 11:06:15 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		pt_putnbr_fd(uintmax_t n, char b, int fd)
{
	int			base;
	static int	count;

	base = 10;
	count = 0;
	b == 'b' ? base = 2 : 10;
	b == 'o' ? base = 8 : 10;
	b == 'x' || b == 'X' ? base = 16 : 10;
	n / base != 0 ? pt_putnbr_fd(n / base, b, fd) : 0;
	if (n % base >= 10)
	{
		b == 'x' ? ft_putchar_fd(n % base - 10 + 'a', fd) : 0;
		b == 'X' ? ft_putchar_fd(n % base - 10 + 'A', fd) : 0;
		count++;
	}
	else
	{
		ft_putchar_fd(n % base + '0', fd);
		count++;
	}
	return (count);
}
