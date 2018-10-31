/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:36:49 by khou              #+#    #+#             */
/*   Updated: 2018/10/31 00:16:38 by khou             ###   ########.fr       */
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
//		ft_printf("%d, ", S_ISDIR(thing.st_mode));
//		ft_printf("%s is a DIR\n", path);
	}
	else
	{
		ls->fil[ls->fi++] = path;
//		ft_printf("%d, ", S_ISDIR(thing.st_mode));
//		ft_printf("%s is a FIL\n", path);
	}
}

void	p_node(t_lsflags *store, t_node *tree)
{
	if (!tree->isDir)
		ft_printf("%s\n", tree->fullpath);
	if (tree->isDir)
	{
		ft_printf("%s:\n\n", tree->fullpath);
		openDir(store, tree->fullpath);
	}
}

void    print_tree(t_lsflags *store, t_node *tree)
{
	if (tree->left)
		print_tree(store, tree->left);
//	ft_printf("%s\n", tree->fullpath);
	p_node(store, tree);
	if (tree->right)
		print_tree(store, tree->right);
}

void    f_sort(t_lsflags *store, t_ls *ls)
{
    t_node *tree = newNode(ls->fil[0]);
    int a = 1;
    while (a < ls->fi)
    {
//		ft_printf("insert: %s\n", ls->fil[a]);
        insert(store, tree ,ls->fil[a]);
        a++;
    }
    print_tree(store, tree);
}

void    d_sort(t_lsflags *store, t_ls *ls)
{
    t_node *tree = newNode(ls->dir[0]);
    int a = 1;
	if (!ls->dir[a])
	{
		openDir(store, ls->dir[0]);
		return ;
	}					
    while (a < ls->di)
    {
//        ft_printf("insert: %s\n", ls->dir[a]);
        insert(store, tree ,ls->dir[a]);
        a++;
    }
    print_tree(store, tree);
}

void cmd_sort(t_lsflags *store, t_ls *ls)
{
    if (ls->fi != 0)
        f_sort(store, ls);
    if (ls->di != 0)
	{
		if (ls->fi != 0)
			ft_printf("\n");
        d_sort(store, ls);
	}
}
