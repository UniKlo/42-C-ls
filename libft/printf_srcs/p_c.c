/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_c.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:48:19 by khou              #+#    #+#             */
/*   Updated: 2018/09/24 15:05:35 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	ft_putwchar(wchar_t wc)
{
	if (wc <= 0x7F)
		ft_putchar(wc);
	else if (wc <= 0x7FF)
	{
		ft_putchar((wc >> 6) + 0xC0);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0xFFFF)
	{
		ft_putchar((wc >> 12) + 0xE0);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
	else if (wc <= 0x10FFFF)
	{
		ft_putchar((wc >> 18) + 0xF0);
		ft_putchar(((wc >> 12) & 0x3F) + 0x80);
		ft_putchar(((wc >> 6) & 0x3F) + 0x80);
		ft_putchar((wc & 0x3F) + 0x80);
	}
}

void	p_c(t_block *blk)
{
	char	c;

	blk->specifier == 'c' || blk->specifier == 'C' ?\
		c = va_arg(*blk->ap, int) : 0;
	blk->specifier == '%' ? c = '%' : 0;
	if (blk->width)
		*blk->ret += blk->width;
	else
		*blk->ret += 1;
	blk->width ? blk->width -= 1 : 0;
	if (blk->left_align)
	{
		write(1, &c, 1);
		while (blk->width-- > 0)
			write(*blk->fd, " ", 1);
	}
	else
	{
		while (blk->width-- > 0)
			write(*blk->fd, " ", 1);
		write(1, &c, 1);
	}
}
