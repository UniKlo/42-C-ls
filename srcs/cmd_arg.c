/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:36:49 by khou              #+#    #+#             */
/*   Updated: 2018/11/10 00:22:52 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void    f_or_d(t_ls *ls, char *path)
{
	struct stat thing;
	
	lstat(path, &thing);
	if (!thing.st_nlink)
	{
		ft_printf("ls: %s: No such file or directory\n", path);
		return ;
	}
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

void	p_cmd(t_lsflags *store, t_node *tree)//open dir, and print the file
{
	if (!tree->isDir)
	{
		if (store->R)
			return;
		ls_fmt(store, tree);
	}
	if (tree->isDir)
	{
//		printf("T:F %d", store->current);
		if (!store->current)
			ft_printf("\n%s:\n", tree->fullpath);
		openDir(store, tree->fullpath);
		
	}
}

void    print_tree(t_lsflags *store, t_node *tree)
{
	if (store->r != 1)
	{
		if (tree->left)
			print_tree(store, tree->left);		
		p_cmd(store, tree);
		if (tree->right)
			print_tree(store, tree->right);
	}
	else
	{
		if (tree->right)
            print_tree(store, tree->right);
    	p_cmd(store, tree);
        if (tree->left)
            print_tree(store, tree->left);
	}
		
}

void    f_sort(t_lsflags *store, t_ls *ls)
{
    t_node *tree = newNode(ls->fil[0]);
    int a = 1;
    while (a < ls->fi)
    {
        insert(store, tree ,ls->fil[a]);
        a++;
    }
	g_free.root[g_free.ri] = tree;
    g_free.ri++;
	print_tree(store, tree);
}

void    d_sort(t_lsflags *store, t_ls *ls)
{
    t_node *tree = newNode(ls->dir[0]);
    int a = 1;
	while (a < ls->di)
    {
        insert(store, tree ,ls->dir[a]);
        a++;
    }
	g_free.root[g_free.ri] = tree;
	g_free.ri++;
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
