/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:35:42 by khou              #+#    #+#             */
/*   Updated: 2018/09/29 11:52:29 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int		width(t_block *blk, char *blk_fmt)
{
	int x;

	x = 0;
	blk->width = ft_atoi(blk_fmt);
	while (ft_isdigit(blk_fmt[++x]))
		;
	return (x - 1);
}

int		p_dot(t_block *blk, char *blk_fmt)
{
	int x;

	x = 0;
	if (ft_isdigit(blk_fmt[x]))
	{
		blk->p_dot = ft_atoi(blk_fmt);
		while (ft_isdigit(blk_fmt[++x]))
			;
	}
	else
		blk->p_dot = -5;
	return (x);
}

int		is_flag(t_block *blk, char c)
{
	if (!ft_strchr("#+-0 ", c))
		return (0);
	blk->hash == 1 || c == '#' ? blk->hash = true : false;
	blk->sign == 1 || c == '+' ? blk->sign = true : false;
	blk->left_align == 1 || c == '-' ? blk->left_align = true : false;
	blk->pad_z == 1 || c == '0' ? blk->pad_z = true : false;
	blk->pad_s == 1 || c == ' ' ? blk->pad_s = true : false;
	return (1);
}

void	valid_all(t_block *blk)
{
	blk->sign == 1 ? blk->pad_s = false : 0;
	blk->p_dot > 0 && blk->specifier != 's' ? blk->pad_z = false : 0;
	blk->left_align == 1 ? blk->pad_z = false : 0;
	blk->specifier == 'u' ? blk->pad_s = false : 0;
	blk->specifier == 'u' ? blk->sign = false : 0;
	if (blk->specifier == 'U')
	{
		!ft_strcmp(blk->length, "\0") ? ft_strcpy(blk->length, "l\0") : 0;
		!ft_strcmp(blk->length, "h\0") ? ft_strcpy(blk->length, "l\0") : 0;
		blk->specifier = 'u';
	}
	if (blk->specifier == 'D')
	{
		!ft_strcmp(blk->length, "\0") ? ft_strcpy(blk->length, "l\0") : 0;
		!ft_strcmp(blk->length, "h\0") ? ft_strcpy(blk->length, "l\0") : 0;
		blk->specifier = 'd';
	}
	(blk->specifier == 's' && !ft_strcmp(blk->length, "l\0")) ?
		blk->specifier = 'S' : 0;
	(blk->specifier == 'c' && !ft_strcmp(blk->length, "l\0")) ?
		blk->specifier = 'C' : 0;
}

int		specifier(t_block *blk, char c)
{
	if ((c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' || c == '%' || c == 'Z' || c == 'b' || c == '*' ||
		c == 'n') &&
		(blk->specifier = c))
	{
		if (blk->specifier == 'p')
		{
			blk->hash = true;
			blk->specifier = 'x';
			ft_strcpy(blk->length, "ll\0");
			blk->p_mark = false;
		}
		else
			return (1);
	}
	return (0);
}
