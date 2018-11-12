/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 01:57:11 by khou              #+#    #+#             */
/*   Updated: 2018/11/11 04:03:23 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		flag_init(t_lsflags *store)
{
	store->R = 0;
	store->a = 0;
	store->t = 0;
	store->r = 0;
	store->l = 0;
	store->current = true;
}

void		ls_init(t_ls *ls)
{
	ls->fi = 0;
	ls->di = 0;
	ls->si = 0;
}

void		wid_init(t_width *wid)
{
	wid->w_lnk = 0;
	wid->w_uid = 0;
	wid->w_gid = 0;
	wid->w_siz = 0;
}
