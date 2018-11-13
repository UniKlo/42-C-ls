/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_fname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 02:06:07 by khou              #+#    #+#             */
/*   Updated: 2018/11/13 02:09:45 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	p_fname(t_lsflags *store, char c, char *path)
{
	char	*fname;
	char	*color;
	char	*bypath;

	bypath = NULL;
	if (c == 'd')
		color = BCYN;
	else if (c == 'l')
		color = KMAG;
	else if (c == 's')
		color = KGRN;
	else if (c == 'p')
		color = KYEL;
	else
		color = KNRM;
	if ((fname = ft_strrchr(path, '/')))
	{
		ft_printf("%s%s%s", color, ++fname, KNRM);
		c == 'l' && store->l ? ft_printf("->") : 0;
	}
	else
		ft_printf("%s%s", color, path, KNRM);
	ft_printf("\n");
}
