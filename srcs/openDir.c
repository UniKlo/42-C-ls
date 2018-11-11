/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 23:05:17 by khou              #+#    #+#             */
/*   Updated: 2018/11/11 00:02:25 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	print_node(t_lsflags *store, t_node *tree)
{
	if (!store->a && ft_strstr(tree->fullpath, "/."))
		return ;
	ls_fmt(store, tree);
}

void	print_sub(t_lsflags *store, t_node *tree)
{
	if (store->r != 1)
	{
		if (tree->left)
			print_sub(store, tree->left);
		print_node(store, tree);
		if (tree->right)
			print_sub(store, tree->right);
	}
	else
	{
		if (tree->right)
			print_sub(store, tree->right);
		print_node(store, tree);
		if (tree->left)
			print_sub(store, tree->left);
	}
}

void	Rprint(t_lsflags *store, t_node *tree)
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
			{
				store->current = false;
				p_cmd(store, tree);
			}
			if (tree->left)
				Rprint(store, tree->left);
		}
    }
}

void	sub_sort(t_lsflags *store, t_ls *ls)
{
	t_node	*tree;
	int		a;

	tree = new_node(ls->sub[0]);
	a = 1;
	while (a < ls->si)
	{
		insert(store, tree,ls->sub[a]);
		a++;
	}
	print_sub(store, tree);
	Rprint(store, tree);
	g_free.root[g_free.ri] = tree;
	g_free.ri++;
}

void	open_dir(t_lsflags *store, char *path)
{
	t_ls			ls;
	DIR				*dr;
	struct dirent	*file;
	char			*tmp;
	char			*fname;
	int				blksize;
	struct stat		sb;
	int				b;

	dr = opendir(path);
	if (dr == NULL)
	{
		if ((fname = ft_strrchr(path, '/')))
			ft_printf("ls: %s: Permission denied\n", ++fname);
		return ;
	}
	ls_init(&ls);
	blksize = 0;
	while ((file = readdir(dr)))
	{
		tmp = ft_strjoin(path, "/");
		ls.sub[ls.si] = ft_strjoin(tmp, file->d_name);
		free(tmp);
		if (store->l)
		{
			if (!store->a && ft_strstr(ls.sub[ls.si], "/."))
				;
			else
				lstat(ls.sub[ls.si], &sb);
			blksize += sb.st_blocks;
		}
		ls.si++;
	}
	if (store->l)
		ft_printf("total %d\n", blksize);
	b = 0;
	sub_sort(store, &ls);
	while (b < ls.si)
	{
		free(ls.sub[b]);
		b++;
	}
	closedir(dr);
}
/*
**1.open dir and put all files into an array.
**2. and it will be sorted as a tree in sub_sort.
**3. free strjoin and the tree.
**4. close dir.
*/
