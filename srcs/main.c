/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:55:09 by khou              #+#    #+#             */
/*   Updated: 2018/11/13 01:57:37 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ls_grab_flag(char flags, t_lsflags *store)
{
	if (flags == 'R')
		store->rec = true;
	else if (flags == 'a')
		store->a = true;
	else if (flags == 't')
		store->t = true;
	else if (flags == 'r')
		store->r = true;
	else if (flags == 'l')
		store->l = true;
	else
		return (-1);
	return (1);
}

void	f_or_d(t_ls *ls, char *path)
{
	struct stat thing;
	int			exist;

	exist = 0;
	exist = lstat(path, &thing);
	if (exist < 0)
	{
		ft_printf("ls: %s: No such file or directory\n", path);
		return ;
	}
	if (S_ISDIR(thing.st_mode))
	{
		ls->dir[ls->di++] = path;
	}
	else
	{
		ls->fil[ls->fi++] = path;
	}
}

int		cmd_arg(char **argv, t_lsflags *store, t_ls *ls)
{
	int i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		!argv[i][1] ? ft_printf("ls: -: No such file or directory\n") : 0;
		while (*(++argv[i]))
		{
			if (ls_grab_flag(*argv[i], store) < 0)
			{
				ft_printf("ls: illegal option -- %c\nusage: \
ls [lRart] [file ...]\n", *argv[i]);
				return (1);
			}
		}
		i++;
	}
	while (argv[i])
	{
		store->current = false;
		f_or_d(ls, argv[i++]);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_lsflags	store;
	t_ls		ls;
	int			b;

	argc = 0;
	g_free.ri = 0;
	flag_init(&store);
	ls_init(&ls);
	if (cmd_arg(argv, &store, &ls))
		return (0);
	if (store.current)
	{
		f_or_d(&ls, "./");
		cmd_sort(&store, &ls);
		return (0);
	}
	if (ls.di == 1)
		store.current = true;
	cmd_sort(&store, &ls);
	b = g_free.ri - 1;
	while (b > -1)
		free_tree(g_free.root[b--]);
//	while (1);
	return (0);
}
