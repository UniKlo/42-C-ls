/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_diuox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:56:00 by khou              #+#    #+#             */
/*   Updated: 2018/09/27 13:13:48 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	establish_write(t_write *act)
{
	act->sign = '\0';
	act->nbr = 0;
	act->length = 0;
	act->space = 0;
	act->zero = 0;
	act->base = 10;
}

void	left_write_blk(char *s, t_block *blk, t_write *act)
{
	(blk->pad_s) && write(*blk->fd, " ", 1);
	act->sign || blk->s_data < 0 ? write(1, &act->sign, 1) : 0;
	*blk->ret += pt_putstr(s, ft_strlen(s));
	while (act->zero-- > 0)
		write(*blk->fd, "0", 1);
	*blk->ret += pt_putnbr(act->nbr, blk->specifier);
	while (act->space-- > 0)
		write(*blk->fd, " ", 1);
}

void	write_blk(char *s, t_block *blk, t_write *act)
{
	(blk->pad_s) && write(*blk->fd, " ", 1);
	blk->pad_z && act->sign ? write(1, &act->sign, 1) : 0;
	blk->pad_z ? *blk->ret += pt_putstr(s, ft_strlen(s)) : 0;
	while (act->space-- > 0)
		blk->pad_z ? write(*blk->fd, "0", 1) : write(*blk->fd, " ", 1);
	!blk->pad_z ? *blk->ret += pt_putstr(s, ft_strlen(s)) : 0;
	!blk->pad_z && act->sign ? write(1, &act->sign, 1) : 0;
	while (act->zero-- > 0)
		write(*blk->fd, "0", 1);
	if ((blk->p_dot < -1 || blk->p_dot == 0) && act->nbr == 0)
		return ;
	else if (blk->hash && blk->p_dot == -1 && blk->specifier == 'o' &&
				act->nbr == 0)
		return ;
	else
		*blk->ret += pt_putnbr(act->nbr, blk->specifier);
}

void	set_blk(t_block *blk, t_write *act)
{
	char *s;

	s = "\0";
	if (blk->hash)
	{
		blk->specifier == 'x' ? s = "0x" : 0;
		blk->specifier == 'X' ? s = "0X" : 0;
		if (act->space - 2 >= 0 && *s)
			act->space -= 2;
		if (blk->p_dot == -1 && act->space > 0 && act->nbr == 0 &&
			(blk->specifier == 'x' || blk->specifier == 'X'))
			act->space += 2;
		*s && act->nbr == 0 && blk->p_mark == 1 ? s = "\0" : 0;
	}
	act->space <= 0 && act->sign ? *blk->ret += 1 : 0;
	act->sign && act->space-- > 0 ? *blk->ret += 1 : 0;
	blk->pad_s && act->sign ? blk->pad_s = false : 0;
	act->space <= 0 && blk->pad_s ? *blk->ret += 1 : 0;
	blk->pad_s && act->space-- > 0 ? *blk->ret += 1 : 0;
	act->space < 0 ? act->space = 0 : 0;
	*blk->ret += act->zero + act->space;
	if (blk->left_align)
		left_write_blk(s, blk, act);
	else
		write_blk(s, blk, act);
}

void	p_diuox(t_block *blk)
{
	uintmax_t	tmp;
	t_write		act;

	establish_write(&act);
	!ft_strchr("uUxXo", blk->specifier) ? signed_lengh(blk, &act) :
		unsigned_lengh(blk, &act);
	tmp = act.nbr;
	act.length = ft_nbrlen(tmp);
	if (blk->hash)
		blk->specifier == 'o' || blk->specifier == 'O' ? act.sign = '0' : 0;
	act.nbr == 0 ? act.length++ : 0;
	act.space = blk->width - bigger(blk->p_dot, act.length);
	act.space < 0 ? act.space = 0 : 0;
	act.zero = (blk->p_dot - act.length);
	act.zero < 0 ? act.zero = 0 : 0;
	if ((blk->p_dot < -1 || blk->p_dot == 0) && act.nbr == 0)
		if (act.space > 0 || act.sign)
		{
			act.space++;
			set_blk(blk, &act);
		}
		else
			return ;
	else
		set_blk(blk, &act);
}
