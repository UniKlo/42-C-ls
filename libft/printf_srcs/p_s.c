/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:11:14 by khou              #+#    #+#             */
/*   Updated: 2018/11/10 23:10:18 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		ft_putwstr(wchar_t *ls, int len)
{
	int		i;

	i = 0;
	while (*ls && i < len)
	{
		if (*ls <= 0x7F)
			i++;
		else if (*ls <= 0x7FF)
			i += 2;
		else if (*ls <= 0xFFFF)
			i += 3;
		else if (*ls <= 0x10FFFF)
			i += 4;
		if (i <= len)
			ft_putchar(*ls++);
	}
	return (i);
}

void	p_ls(t_block *blk, t_write *act, wchar_t *ls)
{
	if (blk->left_align)
	{
		*blk->ret += ft_putwstr(ls, act->length);
		while (act->space-- > 0)
			blk->pad_z ?\
				write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);
	}
	else
	{
		while (act->space-- > 0)
			blk->pad_z ?\
				write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);
		*blk->ret += ft_putwstr(ls, act->length);
	}
}

void	set_ls(t_block *blk)
{
	wchar_t		*ls;
	t_write		act;

	establish_write(&act);
	ls = va_arg(*blk->ap, wchar_t *);
	if (!ls)
		ls = L"(null)";
	blk->p_dot == -1 ? act.length = ft_lstrlen(ls) : blk->p_dot;
	if (blk->p_dot > 0)
	{
		if ((blk->p_dot > ft_lstrlen(ls)) && ft_lstrlen(ls) > 0)
			act.length = ft_lstrlen(ls);
		else
			act.length = blk->p_dot;
	}
	if (blk->width && ft_lstrlen(ls) > 0)
		act.space = blk->width - bigger(blk->p_dot, act.length);
	else
		act.space = blk->width;
	*blk->ret = *blk->ret + act.space;
	p_ls(blk, &act, ls);
}

void	p_s(t_block *blk, t_write *act, char *s)
{
	if (blk->left_align)
	{
		*blk->ret += pt_putstr(s, act->length);
		while (act->space-- > 0)
			blk->pad_z ? ft_putchar('0') : ft_putchar(' ');
	}
	else
	{
		while (act->space-- > 0)
			blk->pad_z ? ft_putchar('0') : ft_putchar(' ');
		*blk->ret += pt_putstr(s, act->length);
	}
}

void	set_s(t_block *blk)
{
	char		*s;
	t_write		act;

	establish_write(&act);
	s = va_arg(*blk->ap, char *);
	if (!s)
		s = "(null)";
	blk->p_dot == -1 ? act.length = ft_strlen(s) : blk->p_dot;
	if (blk->p_dot > 0)
	{
		if ((blk->p_dot > (int)ft_strlen(s)) && ft_strlen(s) > 0)
			act.length = ft_strlen(s);
		else
			act.length = blk->p_dot;
	}
	if (blk->width && ft_strlen(s) > 0)
		act.space = blk->width - act.length;
	else
		act.space = blk->width;
	*blk->ret = *blk->ret + act.space;
	p_s(blk, &act, s);
}
