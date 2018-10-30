/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_dispatch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:22:26 by khou              #+#    #+#             */
/*   Updated: 2018/09/29 11:08:20 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		establish(t_print *all, t_block *blk)
{
	blk->hash = false;
	blk->left_align = false;
	blk->pad_s = false;
	blk->pad_z = false;
	blk->sign = false;
	blk->width = 0;
	blk->p_dot = -1;
	blk->length[0] = '\0';
	blk->length[1] = '\0';
	blk->length[2] = '\0';
	blk->specifier = 0;
	blk->len = 0;
	blk->ap = &all->ap;
	blk->fd = &all->fd;
	blk->ret = &all->ret;
	blk->p_mark = true;
}

void		grab_flag(t_block *blk, char *blk_fmt, int *i)
{
	while (blk_fmt[++*i] && !ft_strchr("sSpdDioOuUxXcC%Zbn*", blk_fmt[*i]))
	{
		if (is_flag(blk, blk_fmt[*i]))
			;
		else if (blk_fmt[*i] == '.')
			*i += p_dot(blk, blk_fmt + *i + 1);
		else if (!blk->width && ft_isdigit(blk_fmt[*i]))
			*i += width(blk, blk_fmt + *i);
		else if (ft_strchr("hlzj", (blk_fmt[*i])))
			*i += length(blk, blk_fmt + *i);
	}
	specifier(blk, blk_fmt[*i]);
	valid_all(blk);
}

t_fun_tbl	dispatch_table(char c)
{
	t_fun_tbl	f[123];

	f['s'] = &set_s;
	f['S'] = &set_ls;
	f['p'] = &p_diuox;
	f['d'] = &p_diuox;
	f['D'] = &p_diuox;
	f['i'] = &p_diuox;
	f['o'] = &p_diuox;
	f['O'] = &p_diuox;
	f['u'] = &p_diuox;
	f['U'] = &p_diuox;
	f['x'] = &p_diuox;
	f['X'] = &p_diuox;
	f['b'] = &p_diuox;
	f['c'] = &p_c;
	f['C'] = &p_c;
	f['%'] = &p_c;
	f['Z'] = &undef;
	f['*'] = &p_c;
	f['n'] = &set_s;
	return (f[(int)c]);
}
