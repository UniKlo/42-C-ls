/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openDir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 23:05:17 by khou              #+#    #+#             */
/*   Updated: 2018/11/01 21:10:49 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sub_init(t_ls *ls)
{
	ls->si = 0;
}

void	ls_fmt(t_lsflags *store, t_node *tree)
{
	if (store->l)
        lsLong(tree->fullpath);
	else
		pFname(tree->fullpath);
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

/*
void    Rprint(t_lsflags *store, t_node *tree)
{
    if (store->r != 1)
    {
    	if (tree->left)
            Rprint(store, tree->left);
		p_cmd(store, tree);
        if (tree->right)
            Rprint(store, tree->right);
    }
    else
    {
	if (tree->right)
    	    Rprint(store, tree->right);
        p_cmd(store, tree);
	if (tree->left)
            Rprint(store, tree->left);
    }
}
*/
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
	printf("I m here in sub_sort.\n");
//	if (store->R)
//		Rprint(store, tree);
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
//		ft_printf("%s\n", file->d_name);
		if (store->R)
			ls.sub[ls.si] = ft_strjoin(path, file->d_name);
		else
		{
			ls.sub[ls.si] = ft_strjoin(path, "/");
			ls.sub[ls.si] = ft_strjoin(ls.sub[ls.si], file->d_name);
//			ft_printf("fullpath: %s\n", ls.sub[ls.si]);
//			ls.si++;
		}
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
	ft_printf("total size of blocks: %.d\n", blksize);
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
	ft_printf("  ----  openDir NL seperation  ----  \n");
}
