/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 23:55:09 by khou              #+#    #+#             */
/*   Updated: 2018/11/10 00:18:52 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	flag_init(t_lsflags *store)
{
	store->R = 0;
	store->a = 0;
	store->t = 0;
	store->r = 0;
	store->l = 0;
	store->current = true;
}
static void		ls_grab_flag(char *flags, t_lsflags *store)
{
	store->R == 1 || ft_strchr(flags, 'R') ? store->R = true : false;
	store->a == 1 || ft_strchr(flags, 'a') ? store->a = true : false; 
	store->t == 1 || ft_strchr(flags, 't') ? store->t = true : false;
	store->r == 1 || ft_strchr(flags, 'r') ? store->r = true : false;
	store->l == 1 || ft_strchr(flags, 'l') ? store->l = true : false;
}

void	ls_init(t_ls *ls)
{
	ls->fi = 0;
	ls->di = 0;
}

int 	main(int argc, char **argv)
{
	int		i = 1;
	t_lsflags	store;
	t_ls	ls;
	
	
	argc = 0;
	g_free.ri = 0;
	flag_init(&store);
	while (argv[i] && argv[i][0] == '-')
	{
		if (!argv[i][1])
			ft_printf("ls: -: No such file or directory\n");
		ls_grab_flag(++argv[i], &store); //get a set of flags
		i++;
	}
	ls_init(&ls);
	while (argv[i]) //loop thru cmd add
	{
		if (argv[i][0] != '-')
		{
			store.current = false;
			f_or_d(&ls, argv[i]);
		}
		else
			ft_printf("ls: %s: No such file or directory\n", argv[i]);//error messages
		i++;
	}
	if (store.current)
	{
		f_or_d(&ls, "./");
		cmd_sort(&store, &ls);
		return (0);
	}
	if (ls.di == 1)
		store.current = true;
	cmd_sort(&store, &ls);
	
    int b = g_free.ri - 1;
	ft_printf("IN MAIN: #of root: %d, index b: %d\n", g_free.ri, b);

    while (b > -1)
    {
        ft_printf("g_free.root[%d]: %s\n",b,  g_free.root[b]->fullpath);
		free_tree(g_free.root[b]);
        b--;
    }

	return (0);
}
