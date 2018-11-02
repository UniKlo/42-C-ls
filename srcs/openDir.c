/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openDir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 23:05:17 by khou              #+#    #+#             */
/*   Updated: 2018/11/02 03:58:32 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sub_init(t_ls *ls)
{
	ls->si = 0;
}

void	print_node(t_lsflags *store, t_node *tree)
{
	if (!store->a && ft_strstr(tree->fullpath, "/."))
		return;
	ls_fmt(store, tree);
}

void    print_sub(t_lsflags *store, t_node *tree)
{
	if (store->r != 1)
	{
		if (tree->left)
			print_sub(store, tree->left);
		print_node(store, tree);
//		ft_printf("%s\n", tree->fullpath);
		if (tree->right)
			print_sub(store, tree->right);
	}
	else
	{
		if (tree->right)
			print_sub(store, tree->right);
		print_node(store, tree);
//		ft_printf("%s\n", tree->fullpath);
		if (tree->left)
			print_sub(store, tree->left);
	}
}

void    Rprint(t_lsflags *store, t_node *tree)
{
	if (store->R)
	{
		if (store->r != 1)
		{
			if (tree->left)
				Rprint(store, tree->left);
			if (!ft_strstr(tree->fullpath, "/."))
			{
				store->current = false;
				p_cmd(store, tree);
			}
			if (tree->right)
				Rprint(store, tree->right);
		}
		else
		{
			if (tree->right)
				Rprint(store, tree->right);
			if (!ft_strstr(tree->fullpath, "/."))
                p_cmd(store, tree);
			if (tree->left)
				Rprint(store, tree->left);
		}
    }
}

void	sub_sort(t_lsflags *store, t_ls *ls)
{
	t_node *tree = newNode(ls->sub[0]);
    int a = 1;
    while (a < ls->si)
    {
//      ft_printf("insert: %s\n", ls->fil[a]);
        insert(store, tree,ls->sub[a]);
        a++;
    }
    print_sub(store, tree);
//	printf("I m here in sub_sort.\n");
	Rprint(store, tree);
}

void	openDir(t_lsflags *store, char *path)
{
	t_ls			ls;
	DIR				*dr = opendir(path);
	struct dirent	*file;
	if (dr == NULL)
		ft_printf("openDir: %s is not readable.\n", path);
	sub_init(&ls);

	int	blksize = 0;
	struct stat sb;
	while ((file = readdir(dr)))
	{
		ls.sub[ls.si] = ft_strjoin(path, "/");
		ls.sub[ls.si] = ft_strjoin(ls.sub[ls.si], file->d_name);
		if (store->l)
        {
			if (!store->a && ft_strstr(ls.sub[ls.si], "/."))
				continue;
 			else
				lstat(ls.sub[ls.si], &sb);
			blksize += sb.st_blocks;
		}
		ls.si++;
	}
	if (store->l)
		ft_printf("total %d\n", blksize);
/*
	int b = 0;
    while (b < ls.si)
    {
        ft_printf("%s\n", ls.sub[b]);
        b++;
    }
	ft_printf("\n"); */
//	store = NULL;
//	while(1);

	sub_sort(store, &ls);
	closedir(dr);//close it at the very end or heap use after free
//	ft_printf("  ----  openDir NL seperation  ----  \n");
}
