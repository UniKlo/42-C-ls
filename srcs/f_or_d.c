/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_or_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 21:33:41 by khou              #+#    #+#             */
/*   Updated: 2018/10/28 02:59:46 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"


void    f_or_d(t_ls *ls, char *path)
{
	struct stat thing;
	
	lstat(path, &thing);
	if (S_ISDIR(thing.st_mode))
	{
		ls->dir[ls->di++] = path;
		ft_printf("is a DIR\n");
	}
	else
	{
		ls->fil[ls->fi++] = path;
		ft_printf("is a FIL\n");
	}
}

